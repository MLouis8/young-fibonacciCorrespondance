#pragma once

#include <array>
#include <cstddef>
#include <iostream>
#include <ostream>
#include <vector>

template <size_t T> struct Permutation {
  std::array<unsigned char, T> permutation;
  std::array<std::array<unsigned char, T>, T> matrix;

  Permutation(std::array<unsigned char, T> tab) : permutation(tab) {}

  size_t get_size() { return permutation.size(); }

  unsigned char get_last() { return permutation.back(); }

  unsigned char &operator[](size_t id) { return permutation[id - 1]; }
};

typedef std::vector<unsigned char> listeEntiere;
typedef std::pair<listeEntiere, listeEntiere> Tableau;
typedef std::pair<listeEntiere, listeEntiere> STableau;
typedef std::vector<unsigned char> Chain;

template <size_t T>
std::ostream &operator<<(std::ostream &os, Permutation<T> p) {
  os << "[";
  for (size_t i = 1; i < p.get_size(); i++)
    os << static_cast<int>(p[i]) << ", ";
  os << static_cast<int>(p.get_last()) << "]" << std::endl;
  return os;
}
