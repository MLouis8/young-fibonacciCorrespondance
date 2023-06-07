#pragma once

#include "../src/display.cpp"
#include "involutionChainList.hpp"
#include "permutation.hpp"
#include <algorithm>
#include <array>
#include <cstddef>
#include <forward_list>
#include <iterator>
#include <numeric>
#include <utility>
#include <list>

typedef std::pair<std::vector<std::array<unsigned char, 2>>,
                  std::vector<std::array<unsigned char, 2>>>
    InvolutionsVector;

typedef std::pair<std::list<std::array<unsigned char, 2>>,
                  std::list<std::array<unsigned char, 2>>>
    InvolutionsList;

typedef std::_List_iterator<std::array<unsigned char, 2>> LIterator;


typedef std::pair<std::forward_list<std::array<unsigned char, 2>>,
                  std::forward_list<std::array<unsigned char, 2>>>
    InvolutionsFList;

typedef std::_Fwd_list_iterator<std::array<unsigned char, 2>> FLIterator;

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

void insertFList(unsigned char key, unsigned char element, InvolutionsFList &l,
                FLIterator prev1, FLIterator prev2, FLIterator it1, FLIterator it2);

template <size_t T> InvolutionsFList robyInsertionFList(Permutation<T> p) {
  /**
   * @brief Roby's Insertion algorithm.
   * @param p a permutation
   * @return a std::pair of InvolutionsCLists (List)
   */
  InvolutionsFList res;
  res.first.push_front({p.call(1), 0});
  res.second.push_front({1, 0});
  for (unsigned char k = 2; k <= p.size(); k++) {
    insertFList(k, p.call(k), res, res.first.before_begin(),
               res.second.before_begin(), res.first.begin(),
               res.second.begin());
  }
  return res;
}

void insertList(unsigned char key, unsigned char element, InvolutionsList &l,
                LIterator it1, LIterator it2);

template <size_t T> InvolutionsList robyInsertionList(Permutation<T> p) {
  /**
   * @brief Roby's Insertion algorithm.
   * @param p a permutation
   * @return a std::pair of InvolutionsCLists (List)
   */
  InvolutionsList res;
  res.first.push_front({p.call(1), 0});
  res.second.push_front({1, 0});
  for (unsigned char k = 2; k <= p.size(); k++) {
    insertList(k, p.call(k), res, res.first.begin(), res.second.begin());
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
void display_chains(std::pair<std::array<size_t, T>, std::array<size_t, T>> a) {
  std::cout << "[ ";
  for (size_t c : a.first) {
    std::cout << c << " ";
  }
  std::cout << "]\n[ ";
  for (size_t c : a.second) {
    std::cout << c << " ";
  }
  std::cout << "]\n";
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

template <size_t T>
std::pair<std::array<size_t, T + 1>, std::array<size_t, T + 1>>
permutationToChains(Permutation<T> p) {
  /**
   * @brief Returns pair of chains in the Young-Fibonacci lattice from a
   * permutation, without computing growth diagram.
   *
   * @param p a permutation
   * @return pair of paths in the Young-Fibonacci graph
   */
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