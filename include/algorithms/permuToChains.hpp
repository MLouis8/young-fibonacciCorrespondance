#pragma once

#include "../involutionChainList.hpp"
#include "../permutation.hpp"

/**
 * @brief Returns pair of chains in the Young-Fibonacci lattice from a
 * permutation, without computing growth diagram.
 *
 * @param p a permutation
 * @return pair of paths in the Young-Fibonacci graph
 */
template <size_t T>
std::pair<std::array<size_t, T + 1>, std::array<size_t, T + 1>>
permutationToChains(Permutation<T> p) {
  std::array<size_t, T + 1> chain1, chain2;
  std::array<bool, T> blacklistQ;
  blacklistQ.fill(true);
  blacklistQ[0] = false;
  std::array<bool, T> blacklistP;
  blacklistP.fill(true);
  blacklistP[p.minBlacklisted(blacklistP) - 1] = false;
  for (unsigned char i = 0; i < T + 1; i++) {
    if (i < 2) {
      chain1[i] = i;
      chain2[i] = i;
    } else {
      blacklistQ[i - 1] = false;
      chain1[i] = computeFiboNode(blacklistQ, p);
      blacklistP[p.minBlacklisted(blacklistP) - 1] = false;
      chain2[i] = computeFiboNode(blacklistP, p);
    }
  }
  return {chain1, chain2};
}

template <size_t T>
size_t computeFiboNode(std::array<bool, T> blacklist, Permutation<T> &p) {
  size_t res = 0;
  unsigned char s = std::accumulate(blacklist.begin(), blacklist.end(), 0);
  while (s < blacklist.size()) {
    std::pair<unsigned char, unsigned char> maxi =
        p.maxNotBlacklisted(blacklist);
    blacklist[maxi.first - 1] = true;
    res = res * 10 + p.fominRule(maxi.first, blacklist);
    s = std::accumulate(blacklist.begin(), blacklist.end(), 0);
  }
  return res;
}