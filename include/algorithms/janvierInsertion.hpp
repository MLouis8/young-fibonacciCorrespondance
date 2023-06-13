#pragma once

#include "../involutionChainList.hpp"
#include "../permutation.hpp"

/**
   * @brief Janvier's modifications of Roby's insertion algorithm
   * @param p a permutation
   * @return a pair of standard Young-Fibonacci Tableaux (involution)
   */
template <size_t T> InvolutionsVector janvierInsertion(Permutation<T> p) {
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
