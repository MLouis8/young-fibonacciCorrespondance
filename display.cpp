#include "include/permutation.hpp"
#include <iostream>

void display_line(listeEntiere l) {
  if (l.empty()) {
    std::cout << "[]";
  } else {
    std::cout << "[";
    for (size_t i = 0; i < l.size() - 1; i++) {
      std::cout << l[i] << ", ";
    }
    std::cout << l.back() << "]";
  }
}

void display_tab(std::pair<listeEntiere, listeEntiere> p) {
  display_line(p.second);
  std::cout << std::endl;
  display_line(p.first);
}
