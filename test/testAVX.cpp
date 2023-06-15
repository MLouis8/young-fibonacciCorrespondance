#include <array>
#include <cstdint>
#include <emmintrin.h>
#include <immintrin.h>
#include <popcntintrin.h>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/algorithms/permuToChains.hpp"
#include "../include/doctest.h"
#include "../src/permuToChainAVX.cpp"

std::array<unsigned char, 16> arr0 = {4, 11, 7,  2, 6, 13, 16, 1,
                                      5, 14, 12, 3, 9, 15, 8,  10};
__m128i perm0 = perm_ar16(arr0);

TEST_CASE("test fonction maxNotBlacklistedId") {
  __m128i mask = zeromask;
  CHECK(maxNotBlacklistedId(permid, mask) == 15);
  blacklist(mask, 15);
  CHECK(maxNotBlacklistedId(permid, mask) == 14);
  blacklist(mask, 14);
  CHECK(maxNotBlacklistedId(permid, mask) == 13);
  CHECK(maxNotBlacklistedId(perm0, mask) == 6);
  CHECK(maxNotBlacklistedId(perm0, mask02) == 6);
  blacklist(mask, 6);
  CHECK(maxNotBlacklistedId(perm0, mask) == 13);
}

TEST_CASE("test fonction blacklist") {
  __m128i m = zeromask;
  blacklist(m, 2);
  CHECK(_mm_movemask_epi8(m) == 4);
  blacklist(m, 7);
  CHECK(_mm_movemask_epi8(m) == 132);
  blacklist(m, 7);
  CHECK(_mm_movemask_epi8(m) == 132);
  blacklist(m, 15);
  CHECK(_mm_movemask_epi8(m) == 132 + 32768);
}

TEST_CASE("test fonction minBlacklistedId") {
  CHECK(minBlacklistedId(perm0, fullmask) == 7);
  CHECK(minBlacklistedId(permid, fullmask) == 0);
  CHECK(minBlacklistedId(id, fullmask) == 0);
  CHECK(minBlacklistedId(id, mask02) == 0);
  CHECK(minBlacklistedId(id, maskneg02) == 14);
}

TEST_CASE("test fonction rule") {
  uint8_t c = 0;
  __m128i mask = zeromask;
  blacklist(mask, 6);
  CHECK(rule(perm0, 6, mask, c) == 2);
  blacklist(mask, 13);
  CHECK(rule(perm0, 13, mask, c) == 2);
  blacklist(mask, 9);
  CHECK(rule(perm0, 9, mask, c) == 2);
  blacklist(mask, 5);
  CHECK(rule(perm0, 5, mask, c) == 2);
  blacklist(mask, 10);
  CHECK(rule(perm0, 10, mask, c) == 1);
  blacklist(mask, 1);
  CHECK(rule(perm0, 1, mask, c) == 2);
  blacklist(mask, 2);
  CHECK(rule(perm0, 2, mask, c) == 2);
  blacklist(mask, 4);
  CHECK(rule(perm0, 4, mask, c) == 1);
  blacklist(mask, 0);
  CHECK(rule(perm0, 0, mask, c) == 2);
}

TEST_CASE("test fonction computeFiboNodeAVX") {
  __m128i mask1 = zeromask;
  CHECK(computeFiboNodeAVX(perm0, mask1) == 222212212);
  blacklist(mask1, 15);
  CHECK(computeFiboNodeAVX(perm0, mask1) == 212212212);
  __m128i mask2 = zeromask;
  blacklist(mask2, 6);
  CHECK(computeFiboNodeAVX(perm0, mask2) == 22222212);
}

// TEST_CASE("test de l'algo de permuToChainAVX") {

// }