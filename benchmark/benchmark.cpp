#include "../include/algorithms.hpp"
#include "../include/involutionChainList.hpp"
#include "../src/algorithms.cpp"
#include "../src/involutionChainList.cpp"
#include <benchmark/benchmark.h>

static void BM_createPermutation(benchmark::State &state) {
  std::array<unsigned char, 7> tab = {2, 7, 1, 5, 6, 4, 3};
  Permutation<7> p1 = Permutation<7>(tab);
}

BENCHMARK(BM_createPermutation);

BENCHMARK_MAIN();
