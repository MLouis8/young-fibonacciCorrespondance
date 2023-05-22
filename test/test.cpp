#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../doctest.h"
#include "../include/permutation.hpp"

TEST_CASE("test de la classe Permutation") {
    std::vector<int> t{ 3, 1, 2, 4 };
    Permutation p = Permutation(t);
    CHECK(p.permutation[1] == 3);
}