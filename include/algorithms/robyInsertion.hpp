#pragma once

#include "../../src/display.cpp"
#include "../involutionChainList.hpp"
#include "../permutation.hpp"

void insertCList(unsigned char key, unsigned char element,
                 InvolutionsCLists &prevs, InvolutionsCLists &act,
                 InvolutionsCLists &heads);

/**
   * @brief Roby's Insertion algorithm.
   * @param p a permutation
   * @return a std::pair of InvolutionsCLists (Chain Lists)
   */
template <size_t T> InvolutionsCLists robyInsertionCList(Permutation<T> p) {
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
