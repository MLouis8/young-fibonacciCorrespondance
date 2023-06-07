#include <array>
#include <iostream>

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