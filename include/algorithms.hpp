#include "involution.hpp"
#include "permutation.hpp"
#include <array>
#include <utility>

void insert(unsigned char key, unsigned char element, Involutions &prevs,
            Involutions &act, Involutions &heads);

template <size_t T> Involutions robyInsertion(Permutation<T> p) {
  /**
   * @brief Roby's Insertion algorithm.
   * @param p a permutation
   * @return a std::pair of involutions
   */
  Involutions heads;
  Involutions act;
  Involutions prevs;
  insertNode(act.first, heads.first, {p.call(1), 0});
  insertNode(act.second, heads.second, {1, 0});
  for (unsigned char k = 2; k <= p.size(); k++) {
    act = heads;
    prevs = {nullptr, nullptr};
    insert(k, p.call(k), prevs, act, heads);
  }
  return heads;
}

template <size_t T>
std::pair<unsigned char, unsigned char>
maxNotBlacklisted(Permutation<T> &p, std::array<bool, T> &blacklist) {
  unsigned char res = p.call(1);
  unsigned char resId = 1;
  for (unsigned char i : p.keys()) {
    if (not blacklist[i - 1] && p.call(i) > res) {
      res = p.call(i);
      resId = i;
    }
  }
  return std::pair<unsigned char, unsigned char>{resId, res};
}

template <size_t T> Involutions janvierInsertion(Permutation<T> p) {
  /**
   * @brief Janvier's modifications of Roby's insertion algorithm
   * @param p a permutation
   * @return a pair of standard Young-Fibonacci Tableaux (involution)
   */
  Involutions res;
  std::array<bool, T> blacklist;
  blacklist.fill(false);
  Involutions last;
  Involutions heads;
  for (unsigned char i = p.size(); i > 0; i--) {
    if (not blacklist[i]) {
      std::cout << "here " << static_cast<int>(i);
      std::pair<unsigned char, unsigned char> maxi =
          maxNotBlacklisted(p, blacklist);
      blacklist[i] = true;
      if (maxi.first == i) {
        insertNode(last.first, heads.first, {p.call(i), 0});
        insertNode(last.second, heads.second, {i, 0});
      } else {
        blacklist[maxi.second] = true;
        insertNode(last.first, heads.first, {p.call(i), maxi.second});
        insertNode(last.second, heads.second, {maxi.first, i});
      }
    }
    if (last.first->next) {
      last.first = last.first->next;
      last.second = last.second->next;
    }
  }
  return res;
}