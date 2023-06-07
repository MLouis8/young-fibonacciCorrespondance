#include "../include/algorithms/robyInsertion.hpp"
#include "../include/algorithms/janvierInsertion.hpp"
#include "../include/algorithms/permuToChains.hpp"
#include "../include/involutionChainList.hpp"
#include "../src/robyInsertion.cpp"
#include "../src/involutionChainList.cpp"
#include "data.cpp"
#include <array>
#include <benchmark/benchmark.h>

static void BM_robyInsertionCL8(benchmark::State& state) {
  std::array<Permutation<8>, 50> perm8 = init8();
  for (auto _ : state)
    for (auto p: perm8)
      robyInsertionCList(p);
}

static void BM_robyInsertionCL64(benchmark::State& state) {
  std::array<Permutation<64>, 50> perm64 = init64();
  for (auto _ : state)
    for (auto p: perm64)
      robyInsertionCList(p);
}

static void BM_robyInsertionCL20(benchmark::State& state) {
  std::array<Permutation<20>, 1000> perm20 = init20();
  for (auto _ : state)
    for (auto p: perm20)
        robyInsertionCList(p);
}
BENCHMARK(BM_robyInsertionCL8);
BENCHMARK(BM_robyInsertionCL64);
BENCHMARK(BM_robyInsertionCL20);

static void BM_robyInsertionFL8(benchmark::State& state) {
  std::array<Permutation<8>, 50> perm8 = init8();
  for (auto _ : state)
    for (auto p: perm8)
      robyInsertionFList(p);
}

static void BM_robyInsertionFL64(benchmark::State& state) {
  std::array<Permutation<64>, 50> perm64 = init64();
  for (auto _ : state)
    for (auto p: perm64)
      robyInsertionFList(p);
}

static void BM_robyInsertionFL20(benchmark::State& state) {
  std::array<Permutation<20>, 1000> perm20 = init20();
  for (auto _ : state)
    for (auto p: perm20)
        robyInsertionFList(p);
}
BENCHMARK(BM_robyInsertionFL8);
BENCHMARK(BM_robyInsertionFL64);
BENCHMARK(BM_robyInsertionFL20);

static void BM_robyInsertionL8(benchmark::State& state) {
  std::array<Permutation<8>, 50> perm8 = init8();
  for (auto _ : state)
    for (auto p: perm8)
      robyInsertionList(p);
}

static void BM_robyInsertionL64(benchmark::State& state) {
  std::array<Permutation<64>, 50> perm64 = init64();
  for (auto _ : state)
    for (auto p: perm64)
      robyInsertionList(p);
}

static void BM_robyInsertionL20(benchmark::State& state) {
  std::array<Permutation<20>, 1000> perm20 = init20();
  for (auto _ : state)
    for (auto p: perm20)
        robyInsertionList(p);
}
BENCHMARK(BM_robyInsertionL8);
BENCHMARK(BM_robyInsertionL64);
BENCHMARK(BM_robyInsertionL20);

static void BM_robyInsertionV8(benchmark::State& state) {
  std::array<Permutation<8>, 50> perm8 = init8();
  for (auto _ : state)
    for (auto p: perm8)
      robyInsertionVector(p);
}

static void BM_robyInsertionV64(benchmark::State& state) {
  std::array<Permutation<64>, 50> perm64 = init64();
  for (auto _ : state)
    for (auto p: perm64)
      robyInsertionVector(p);
}

static void BM_robyInsertionV20(benchmark::State& state) {
  std::array<Permutation<20>, 1000> perm20 = init20();
  for (auto _ : state)
    for (auto p: perm20)
        robyInsertionVector(p);
}
BENCHMARK(BM_robyInsertionV8);
BENCHMARK(BM_robyInsertionV64);
BENCHMARK(BM_robyInsertionV20);

static void BM_janvierInsertion8(benchmark::State& state) {
  std::array<Permutation<8>, 50> perm8 = init8();
  for (auto _ : state)
    for (auto p: perm8)
      janvierInsertion(p);
}

static void BM_janvierInsertion64(benchmark::State& state) {
  std::array<Permutation<64>, 50> perm64 = init64();
  for (auto _ : state)
    for (auto p: perm64)
      janvierInsertion(p);
}

static void BM_janvierInsertion20(benchmark::State& state) {
  std::array<Permutation<20>, 1000> perm20 = init20();
  for (auto _ : state)
    for (auto p: perm20)
        janvierInsertion(p);
}
BENCHMARK(BM_janvierInsertion8);
BENCHMARK(BM_janvierInsertion64);
BENCHMARK(BM_janvierInsertion20);

static void BM_permutationToChains8(benchmark::State& state) {
  std::array<Permutation<8>, 50> perm8 = init8();
  for (auto _ : state)
    for (auto p: perm8)
      permutationToChains(p);
}

static void BM_permutationToChains64(benchmark::State& state) {
  std::array<Permutation<64>, 50> perm64 = init64();
  for (auto _ : state)
    for (auto p: perm64)
      permutationToChains(p);
}

static void BM_permutationToChains20(benchmark::State& state) {
  std::array<Permutation<20>, 1000> perm20 = init20();
  for (auto _ : state)
    for (auto p: perm20)
        permutationToChains(p);
}
BENCHMARK(BM_permutationToChains8);
BENCHMARK(BM_permutationToChains64);
BENCHMARK(BM_permutationToChains20);

BENCHMARK_MAIN();