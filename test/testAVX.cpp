#include <array>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "../src/permuToChainAVX.cpp"
#include "../include/algorithms/permuToChains.hpp"

std::array<unsigned char, 16> arr0 = {4, 11, 7, 2, 6, 13, 16, 1, 5, 14, 12, 3, 9, 15, 8, 10};
__m128i perm0 = perm_ar16(arr0);

TEST_CASE("test fonction maxNotBlacklistedId") {
    __m128i mask = zeromask;
    CHECK(maxNotBlacklistedId(permid, mask) == 16);
    blacklist(mask, 15);
    CHECK(maxNotBlacklistedId(permid, mask) == 15);
    blacklist(mask, 14);
    CHECK(maxNotBlacklistedId(permid, mask) == 14);
    CHECK(maxNotBlacklistedId(perm0, mask) == 7);
    CHECK(maxNotBlacklistedId(perm0, mask02) == 7);
    blacklist(mask, 6);
    CHECK(maxNotBlacklistedId(perm0, mask) == 14);
}

// TEST_CASE("test fonction blacklist") {
    
// }

// TEST_CASE("test fonction minNotBlacklistedId") {
    
// }

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