#include <cilk/cilk.h>
#include <chrono>
#include "../src/permuToChainAVX.cpp"
#include "../include/algorithms/permuToChains.hpp"
#include "data.cpp"

std::array<__m128i, 50> perm16AVX = init16AVX();
std::array<Permutation<16>, 50> perm16 = init16();

int main(int argc, char **argv) {
  clock_t startAVX, endAVX, start, end;
  startAVX = clock();
  for (auto p : perm16AVX)
    permutation16ToChainsAVX(p);
  endAVX = clock();

  start = clock();
  for (auto p : perm16)
      permutationToChains(p);
  end = clock();
  std::cout << "with AVX and Cilk: " << ((float) endAVX-startAVX)*1000/CLOCKS_PER_SEC << "ms\n";
  std::cout << "without: " << ((float) end-start)*1000/CLOCKS_PER_SEC << "ms\n";
  return 0;
}