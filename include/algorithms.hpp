#pragma once

#include "../src/display.cpp"
#include "involutionChainList.hpp"
#include "permutation.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <numeric>
#include <utility>

void insertCList(unsigned char key, unsigned char element,
                 InvolutionsCLists &prevs, InvolutionsCLists &act,
                 InvolutionsCLists &heads);

template <size_t T> InvolutionsCLists robyInsertionCList(Permutation<T> p) {
  /**
   * @brief Roby's Insertion algorithm.
   * @param p a permutation
   * @return a std::pair of InvolutionsCLists (Chain Lists)
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

void insertVector(unsigned char key, unsigned char element,
                  InvolutionsVector &v, size_t id);

template <size_t T> InvolutionsVector robyInsertionVector(Permutation<T> p) {
  /**
   * @brief Roby's Insertion algorithm.
   * @param p a permutation
   * @return a std::pair of InvolutionsCLists (Vector)
   */
  InvolutionsVector res;
  res.first.push_back({p.call(1), 0});
  res.second.push_back({1, 0});
  for (unsigned char k = 2; k <= p.size(); k++) {
    insertVector(k, p.call(k), res, 0);
  }
  return res;
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
void display_chains(
    std::pair<std::array<unsigned char, T>, std::array<unsigned char, T>> a) {
  std::cout << "[ ";
  for (unsigned char c : a.first) {
    std::cout << static_cast<int>(c) << " ";
  }
  std::cout << "]\n[ ";
  for (unsigned char c : a.second) {
    std::cout << static_cast<int>(c) << " ";
  }
  std::cout << "]\n";
}

template <size_t T>
unsigned char computeFiboNode(std::array<bool, T> blacklist,
                              Permutation<T> &p) {
  unsigned char res = 0;
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

template <size_t T>
std::pair<std::array<unsigned char, T + 1>, std::array<unsigned char, T + 1>>
permutationToChains(Permutation<T> p) {
  /**
   * @brief Returns pair of chains in the Young-Fibonacci lattice from a
   * permutation, without computing growth diagram.
   *
   * @param p a permutation
   * @return pair of paths in the Young-Fibonacci graph
   */
  std::array<unsigned char, T + 1> chain1, chain2;
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