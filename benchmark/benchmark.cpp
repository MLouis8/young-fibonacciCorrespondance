#include "../include/algorithms.hpp"
#include "../include/involutionChainList.hpp"
#include "../src/algorithms.cpp"
#include "../src/involutionChainList.cpp"
#include <benchmark/benchmark.h>

static void BM_createPermutation(benchmark::State& state) {
  for (auto _ : state)
    Permutation<7> p1 = Permutation<7>({2, 7, 1, 5, 6, 4, 3});
}
BENCHMARK(BM_createPermutation);

BENCHMARK_MAIN();