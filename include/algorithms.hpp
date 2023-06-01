#pragma once

#include "../src/display.cpp"
#include "involutionChainList.hpp"
#include "permutation.hpp"
#include <array>
#include <utility>

void insertCList(unsigned char key, unsigned char element,
                 InvolutionsCLists &prevs, InvolutionsCLists &act,
                 InvolutionsCLists &heads);

template <size_t T> InvolutionsCLists robyInsertionCList(Permutation<T> p) {
  /**
   * @brief Roby's Insertion algorithm.
   * @param p a permutation
   * @return a std::pair of InvolutionsCLists
   */
  InvolutionsCLists heads;
  InvolutionsCLists act;
  InvolutionsCLists prevs;
  insertNode(act.first, heads.first, {p.call(1), 0});
  insertNode(act.second, heads.second, {1, 0});
  for (unsigned char k = 2; k <= p.size(); k++) {
    act = heads;
    prevs = {nullptr, nullptr};
    insertCList(k, p.call(k), prevs, act, heads);
  }
  return heads;
}

template <size_t T>
std::pair<unsigned char, unsigned char>
maxNotBlacklisted(Permutation<T> &p, std::array<bool, T> &blacklist) {
  unsigned char res = 0;
  unsigned char resId = 0;
  for (unsigned char i : p.keys()) {
    if (not blacklist[i - 1] && p.call(i) > res) {
      res = p.call(i);
      resId = i;
    }
  }
  return std::pair<unsigned char, unsigned char>{resId, res};
}

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
          maxNotBlacklisted(p, blacklist);
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