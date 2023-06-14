#include <array>
#include <cassert>
#include <cstddef>
#include <cstdint>
#include <emmintrin.h>
#include <immintrin.h>
#include <iomanip>
#include <iostream>
#include <smmintrin.h>
#include <tmmintrin.h>
#include <x86intrin.h>
// #include <cilk/cilk.h>

#include "../include/permutation.hpp"

// rappel fonctionnement masks: 0 -> element est valide; 255 -> element n'est pas disponible (blacklisted, masked)

using namespace std;
using ar16 = array<uint8_t, 16>;
// using perm = uint8_t __attribute__((vector_size(16), __may_alias__));
using converter = union {
  ar16 p;
  __m128i v8;
};

ar16 ar16_perm(__m128i v) {
  converter c;
  c.v8 = v;
  return c.p;
}

__m128i perm_ar16(ar16 p) {
  converter c;
  c.p = p;
  return c.v8;
}

ostream &operator<<(ostream &stream, ar16 const &ar) {
  stream << "[ " << static_cast<int>(ar[0]);
  for (unsigned i = 1; i < 16; ++i)
    stream << ", " << static_cast<int>(ar[i]);
  stream << " ]";
  return stream;
}

ostream &operator<<(ostream &stream, __m128i const &p) {
  stream << ar16_perm(p);
  return stream;
}

const ar16 ar16pid = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
const ar16 ar16id = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const ar16 ar16zero = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const ar16 ar16shift1 = {15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
const ar16 ar16shift2 = {14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const ar16 ar16shift4 = {12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const ar16 ar16shift8 = {8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7};

const ar16 arrbl02 = {255, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const __m128i permid = perm_ar16(ar16pid);
const __m128i id = perm_ar16(ar16id);
const __m128i zeromask = perm_ar16(ar16zero);
const __m128i fullmask = perm_ar16({255, 255, 255, 255, 255, 255, 255, 255, 255,
                                    255, 255, 255, 255, 255, 255, 255});

const std::vector<__m128i> shift_array = {
    perm_ar16(ar16shift1), perm_ar16(ar16shift2), perm_ar16(ar16shift4),
    perm_ar16(ar16shift8)};

const __m128i mask02 = perm_ar16(arrbl02);

inline void blacklist(__m128i &bl, uint8_t pos) {
  __m128i vecPos = _mm_broadcastb_epi8(zeromask+pos);
  bl += _mm_cmpeq_epi8(vecPos, id);
}

inline __m128i apply_blacklist(const __m128i p, const __m128i bl) {
  return _mm_blendv_epi8(p, zeromask, bl);
}

inline __m128i apply_blacklist255(const __m128i p, const __m128i bl) {
  return _mm_blendv_epi8(p, fullmask, bl);
}

inline __m128i apply_rev_blacklist(const __m128i p, const __m128i bl) {
  return _mm_blendv_epi8(zeromask, p, bl);
}

inline __m128i apply_rev_blacklist255(const __m128i p, const __m128i bl) {
  return _mm_blendv_epi8(fullmask, p, bl);
}

uint8_t max_epi8(__m128i p) {
  for (__m128i shift_p : shift_array)
    p = _mm_max_epi8(p, _mm_shuffle_epi8(p, shift_p));
  return p[0];
}

uint8_t maxNotBlacklisted(__m128i p, __m128i bl) {
  p = apply_blacklist(p, bl);
  return max_epi8(p);
}

uint8_t min_epi8(__m128i p) {
  __m128i mask;
  for (__m128i shift_p : shift_array)
    p = _mm_min_epu8(p, _mm_shuffle_epi8(p, shift_p));
  return p[0];
}

uint8_t minBlacklisted(__m128i p, __m128i bl) {
  p = apply_rev_blacklist255(p, bl);
  return min_epi8(p);
}

uint8_t minBlacklistedId(__m128i p, __m128i bl) {
  p = apply_rev_blacklist255(p, bl);
  __m128i idx, m, p_shifted, idx_shifted;
  idx = permid;
  for (__m128i shift_p : shift_array) {
    p_shifted = _mm_shuffle_epi8(p, shift_p);
    idx_shifted = _mm_shuffle_epi8(idx, shift_p);
    m = _mm_cmpgt_epi8(p_shifted, p);
    p = _mm_blendv_epi8(p_shifted, p, m);
    idx = _mm_blendv_epi8(idx_shifted, idx, m);
  }
  return idx[0];
}

uint8_t maxNotBlacklistedId(__m128i p, __m128i bl) {
  p = apply_blacklist(p, bl);
  std::cout << "bl applied:" << p;
  __m128i idx, m, p_shifted, idx_shifted;
  idx = permid;
  for (__m128i shift_p : shift_array) {
    p_shifted = _mm_shuffle_epi8(p, shift_p);
    idx_shifted = _mm_shuffle_epi8(idx, shift_p);
    m = _mm_cmpgt_epi8(p, p_shifted);
    p = _mm_blendv_epi8(p_shifted, p, m);
    idx = _mm_blendv_epi8(idx_shifted, idx, m);
  }
  return idx[0];
}