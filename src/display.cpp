#include "../include/involutionChainList.hpp"
#include <array>
#include <iostream>

void display_involution(std::vector<std::array<unsigned char, 2>> v) {
  std::cout << "[ ";
  for (std::array<unsigned char, 2> a : v) {
    std::cout << static_cast<int>(a[1]) << " ";
  }
  std::cout << "]" << std::endl << "[ ";
  for (std::array<unsigned char, 2> a : v) {
    std::cout << static_cast<int>(a[0]) << " ";
  }
  std::cout << "]" << std::endl;
}
