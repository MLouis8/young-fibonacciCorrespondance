#include <array>
#include <cstdint>
#include <emmintrin.h>
#include <immintrin.h>
#include <popcntintrin.h>
#include <utility>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/algorithms/permuToChains.hpp"
#include "../include/doctest.h"
#include "../src/permuToChainAVX.cpp"

const ar16 arr0 = {4, 11, 7, 2, 6, 13, 16, 1, 5, 14, 12, 3, 9, 15, 8, 10};
__m128i perm0 = perm_ar16(arr0);
const ar16 arr1 = {5, 8, 7, 10, 13, 16, 4, 3, 1, 12, 11, 14, 6, 9, 2, 15};
__m128i perm1 = perm_ar16(arr1);
const ar16 arr2 = {6, 7, 11, 5, 1, 14, 10, 15, 16, 8, 9, 12, 3, 2, 13, 4};
__m128i perm2 = perm_ar16(arr2);
const ar16 arr3 = {2, 12, 13, 16, 11, 4, 10, 6, 14, 15, 9, 8, 3, 1, 7, 5};
__m128i perm3 = perm_ar16(arr3);

typedef std::pair<std::array<std::size_t, 17>, std::array<std::size_t, 17>>
    chainPair;

chainPair check0 = {{0, 1, 11, 21, 211, 221, 1221, 11221, 21221, 22221, 22222,
                     212222, 222222, 2222212, 22212212, 212212212, 222212212},
                    {0, 1, 2, 12, 22, 221, 2121, 2221, 12221, 22221, 122221,
                     222221, 2212221, 2222221, 2222222, 22222212, 222212212}};
chainPair check1 = {{0, 1, 11, 21, 121, 1121, 11121, 21121, 22121, 22221,
                     222211, 222221, 2212221, 21212221, 22212221, 22222221,
                     222212221},
                    {0, 1, 11, 21, 22, 221, 222, 2122, 2222, 22221, 212221,
                     222221, 222222, 2222221, 22212221, 122212221, 222212221}};
chainPair check2 = {{0, 1, 11, 111, 211, 221, 1221, 2221, 12221, 112221, 212221,
                     222221, 222222, 2222122, 2222222, 22212222, 22222222},
                    {0, 1, 11, 21, 121, 221, 2211, 2221, 2222, 22221, 22222,
                     222122, 2221122, 2222122, 21222122, 22222122, 22222222}};
chainPair check3 = {
    {0, 1, 11, 111, 1111, 2111, 2211, 2221, 22211, 22221, 212221, 2112221,
     2212221, 2222221, 22222211, 222222111, 222222211},
    {0, 1, 2, 21, 211, 1211, 2211, 2221, 21221, 22221, 222211, 2222111,
     22221111, 22222111, 222221111, 222222111, 222222211}};

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

TEST_CASE("test de l'algo de permuToChainAVX") {
  auto res = permutation16ToChainsAVX(perm0);
  CHECK(res.first == check0.first);
  CHECK(res.second == check0.second);
  res = permutation16ToChainsAVX(perm1);
  CHECK(res.first == check1.first);
  CHECK(res.second == check1.second);
  res = permutation16ToChainsAVX(perm2);
  CHECK(res.first == check2.first);
  CHECK(res.second == check2.second);
  res = permutation16ToChainsAVX(perm3);
  CHECK(res.first == check3.first);
  CHECK(res.second == check3.second);
}