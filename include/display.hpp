#include <array>
#include <cstddef>
#include <immintrin.h>
#include <iostream>
#include <ostream>

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

template <size_t T> void display_AVX_vector(__m256i v) {
  int buffer[T];
  _mm256_storeu_epi8((__m256i *)buffer, v);
  for (size_t i = 0; i < T; i++)
    std::cout << buffer[i] << " ";
  std::cout << std::endl;
}