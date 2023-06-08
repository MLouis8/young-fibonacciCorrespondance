#include <array>
#include <cstddef>
#include <cstdint>
#include <immintrin.h>
#include <iomanip>
#include <iostream>
#include <smmintrin.h>

#include "../include/permutation.hpp"

using namespace std;
using ar16 = array<uint8_t, 16>;
using perm = uint8_t __attribute__((vector_size(16), __may_alias__));
using converter = union {
  ar16 p;
  perm v8;
};

ar16 ar16_perm(perm v) {
  converter c;
  c.v8 = v;
  return c.p;
}

perm perm_ar16(ar16 p) {
  converter c;
  c.p = p;
  return c.v8;
}

ostream &operator<<(ostream &stream, ar16 const &ar) {
  stream << "[" << setw(2) << hex << unsigned(ar[0]);
  for (unsigned i = 1; i < 16; ++i)
    stream << "," << setw(2) << hex << unsigned(ar[i]) << dec;
  stream << "]";
  return stream;
}

ostream &operator<<(ostream &stream, perm const &p) {
  stream << ar16_perm(p);
  return stream;
}

const ar16 ar16id = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
const ar16 ar16zero = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

const ar16 ar16shift1 = {15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
const ar16 ar16shift2 = {14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
const ar16 ar16shift4 = {12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
const ar16 ar16shift8 = {8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2, 3, 4, 5, 6, 7};

const ar16 bl3 = {1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const ar16 bl4 = {1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const ar16 bl5 = {1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const ar16 bl6 = {1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const ar16 bl7 = {1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0};
const ar16 bl8 = {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
const ar16 bl9 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0};
const ar16 bl10 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0};
const ar16 bl11 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0};
const ar16 bl12 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0};
const ar16 bl13 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0};
const ar16 bl14 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0};
const ar16 bl15 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0};
const ar16 bl16 = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

const perm permid = perm_ar16(ar16id);
const perm permzero = perm_ar16(ar16zero);

const perm permshift1= perm_ar16(ar16shift1);
const perm permshift2 = perm_ar16(ar16shift2);
const perm permshift4 = perm_ar16(ar16shift4);
const perm permshift8 = perm_ar16(ar16shift8);

const perm permbl3 = perm_ar16(bl3);
const perm permbl4 = perm_ar16(bl4);
const perm permbl5 = perm_ar16(bl5);
const perm permbl6 = perm_ar16(bl6);
const perm permbl7 = perm_ar16(bl7);
const perm permbl8 = perm_ar16(bl8);
const perm permbl9 = perm_ar16(bl9);
const perm permbl10 = perm_ar16(bl10);
const perm permbl11 = perm_ar16(bl11);
const perm permbl12 = perm_ar16(bl12);
const perm permbl13 = perm_ar16(bl13);
const perm permbl14 = perm_ar16(bl14);
const perm permbl15 = perm_ar16(bl15);
const perm permbl16 = perm_ar16(bl16);


perm apply_blacklist(const perm p, const perm bl) {
    return _mm_blendv_epi8(permzero, p, bl);
}

// perm rule(perm p, uint8_t max) {
//     perm perm_max = _mm_broadcastb_epi8(max);
// }

void maxNotBlacklisted(perm p, perm bl) {
    perm p_blacklisted = apply_blacklist(p, bl);
    // apply shifts and max on every shift
    // return the value contained a the first pos
    return; //_mm256_extract_epi8(p, 0);
}