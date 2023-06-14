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

// TEST_CASE("test fonction rule") {

// }

// TEST_CASE("test fonction computeFiboNodeAVX") {

// }

// TEST_CASE("test de l'algo de permuToChainAVX") {
//     auto check = permutationToChains(Permutation<16>(arr0));
//     auto res = permutation16ToChainsAVX(perm0);
//     CHECK(res.first == check.first);
//     CHECK(res.second == check.second);
// }