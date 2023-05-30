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
  insertNode(act.first, heads.first, {p[1], 0});
  insertNode(act.second, heads.second, {1, 0});
  for (unsigned char k = 2; k <= p.get_size(); k++) {
    act = heads;
    prevs = {nullptr, nullptr};
    insert(k, p[k], prevs, act, heads);
  }
  return heads;
}

template <size_t T>
std::pair<unsigned char, unsigned char>
maxNotBlacklisted(Permutation<T> &p, std::array<bool, T> &blacklist) {
  unsigned char res = p[1];
  unsigned char resId = 1;
  for (unsigned char i : p.get_keys()) {
    if (not blacklist[i - 1] && p[i] > res) {
      res = p[i];
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
  std::fill(blacklist.begin(), blacklist.end(), false);
  Involutions last;
  Involutions heads;
  for (unsigned char i = p.get_size(); i > 0; i--) {
    if (not blacklist[i]) {
      std::cout << "here " << static_cast<int>(i);
      std::pair<unsigned char, unsigned char> maxi =
          maxNotBlacklisted(p, blacklist);
      blacklist[i] = true;
      if (maxi.first == i) {
        insertNode(last.first, heads.first, {p[i], 0});
        insertNode(last.second, heads.second, {i, 0});
      } else {
        blacklist[maxi.second] = true;
        insertNode(last.first, heads.first, {p[i], maxi.second});
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