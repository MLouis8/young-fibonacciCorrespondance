#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <numeric>
#include <ostream>
#include <stdexcept>
#include <vector>

template <size_t T> class Permutation {
  std::array<unsigned char, T> permutation;

  void check_permu(std::array<unsigned char, T> tab) {
    std::array<unsigned char, T> contains;
    contains.fill(false);
    for (unsigned char c : tab)
      contains[c - 1]++;
    for (unsigned char c : contains) {
      if (c != 1)
        throw std::invalid_argument(
            "Values must be within [1, array.size] and must appear only once.");
    }
  }

  Permutation(std::array<unsigned char, T> tab, bool check) : permutation(tab) {
    if (check)
      check_permu(tab);
  }

public:
  Permutation() {
    std::array<unsigned char, T> tab;
    std::iota(tab.begin(), tab.end(), 1);
    permutation(tab);
  }

  Permutation(std::array<unsigned char, T> tab) : permutation(tab) {
    check_permu(tab);
  }

  std::array<unsigned char, T> keys() const {
    std::array<unsigned char, T> res;
    std::iota(res.begin(), res.end(), 1);
    return res;
  }

  unsigned char size() const { return permutation.size(); }

  unsigned char back() const { return permutation.back(); }

  unsigned char call(unsigned char id) const { return permutation[id - 1]; }

  std::pair<unsigned char, unsigned char>
  maxNotBlacklisted(std::array<bool, T> blacklist) const {
    unsigned char res = 0;
    unsigned char resId = 0;
    for (unsigned char i : keys()) {
      if (not blacklist[i - 1] && call(i) > res) {
        res = call(i);
        resId = i;
      }
    }
    return std::pair<unsigned char, unsigned char>{resId, res};
  }

  unsigned char minBlacklisted(std::array<bool, T> blacklist) const {
    unsigned char res = size()+1;
    unsigned char resId = 0;
    for (unsigned char i : keys()) {
      if (blacklist[i - 1] && call(i) < res) {
        res = call(i);
        resId = i;
      }
    }
    return resId;
  }

  unsigned char fominRule(unsigned char idMax, std::array<bool, T> &blacklist) {
    unsigned char ele;
    bool flag = true;
    for (unsigned char i = idMax - 1; i < blacklist.size(); i++) {
      if (not blacklist[i]) {
        ele = i;
        flag = false;
      }
    }
    if (flag) {
      return 1;
    } else {
      blacklist[ele] = true;
      return 2;
    }
  }
};

template <size_t T>
std::ostream &operator<<(std::ostream &os, Permutation<T> p) {
  os << "[";
  for (size_t i = 1; i < p.size(); i++)
    os << static_cast<int>(p.call(i)) << ", ";
  os << static_cast<int>(p.back()) << "]" << std::endl;
  return os;
}
