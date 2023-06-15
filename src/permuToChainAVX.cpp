#include "avxLib.cpp"
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <emmintrin.h>
#include <immintrin.h>
#include <popcntintrin.h>
#include <smmintrin.h>
#include <x86intrin.h>

int rule(__m128i p, uint8_t idMax, __m128i &bl, uint8_t &cpt) {
  p = apply_blacklist(p, bl);
  cpt++;
  int msb = _mm_movemask_epi8(_mm_blendv_epi8(fullmask, zeromask, bl));
  uint8_t pos = _bit_scan_reverse(msb);
  if (pos <= idMax) {
    return 1;
  } else {
    blacklist(bl, pos);
    cpt++;
    return 2;
  }
}

size_t computeFiboNodeAVX(__m128i p, __m128i bl) {
  size_t res = 0;
  uint8_t cpt, idMax;
  cpt = _mm_popcnt_u32(_mm_movemask_epi8(bl));
  while (cpt < 16) {
    idMax = maxNotBlacklistedId(p, bl);
    blacklist(bl, idMax);
    res = res * 10 + rule(p, idMax, bl, cpt);
  }
  return res;
}

/**
 * @brief Returns pair of chains in the Young-Fibonacci lattice from a
 * permutation. Computing each node in parallel. And each computation is done
 * with AVX instruction set.
 *
 * @param p a __m128i permutation
 * @return pair of paths in the Young-Fibonacci graph
 */
std::pair<std::array<std::size_t, 17>, std::array<size_t, 17>>
permutation16ToChainsAVX(__m128i p) {
  __m128i blacklistQ = zeromask;
  __m128i blacklistP = zeromask;
  std::array<size_t, 17> chain1, chain2;
  for (int i = 16; i >= 2; i--) {
    // cilk_scope {
    //   cilk_spawn;
    // }
    chain1[i] = computeFiboNodeAVX(p, blacklistP);
    chain2[i] = computeFiboNodeAVX(p, blacklistQ);
    blacklist(blacklistP, maxNotBlacklistedId(p, blacklistP));
    blacklist(blacklistQ, i - 1);
  }
  for (int i = 0; i < 2; i++) {
    chain1[i] = i;
    chain2[i] = i;
  }
  return {chain2, chain1};
}