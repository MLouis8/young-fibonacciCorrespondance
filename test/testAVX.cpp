#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "../src/avxLib.cpp"

// TEST_CASE("test de la fonction maxNotBlacklisted, version avec AVX") {
// }
TEST_CASE("tests AVX") {
    __m128i id = permid;
    __m128i zero = permzero;
    uint8_t res = maxNotBlacklisted(id, fullmask);
    CHECK(16 == res);
}