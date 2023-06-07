#pragma once

#include "../involutionChainList.hpp"
#include "../permutation.hpp"

template <size_t T> InvolutionsVector janvierInsertion(Permutation<T> p) {
  /**
   * @brief Janvier's modifications of Roby's insertion algorithm
   * @param p a permutation
   * @return a pair of standard Young-Fibonacci Tableaux (involution)
   */
  InvolutionsVector res;
  std::array<bool, T> blacklist;
  blacklist.fill(false);
  for (unsigned char i = p.size(); i > 0; i--) {
    if (not blacklist[i - 1]) {
      std::pair<unsigned char, unsigned char> maxi =
          p.maxNotBlacklisted(blacklist);
      blacklist[i - 1] = true;
      if (maxi.first == i) {
        res.first.push_back({p.call(i), 0});
        res.second.push_back({i, 0});
      } else {
        blacklist[maxi.first - 1] = true;
        res.first.push_back({p.call(i), maxi.second});
        res.second.push_back({maxi.first, i});
      }
    }
  }
  return res;
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
