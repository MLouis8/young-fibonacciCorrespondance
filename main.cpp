#include <array>
#include <cstring>
#include <immintrin.h>

#include "include/algorithms/janvierInsertion.hpp"
#include "include/algorithms/permuToChains.hpp"
#include "include/display.hpp"
#include "src/display.cpp"
#include "src/involutionChainList.cpp"
#include "src/robyInsertion.cpp"

int main(int, char **) {
  std::cout << "Hello, world!\n";
  std::array<unsigned char, 7> tab = {2, 7, 1, 5, 6, 4, 3};
  Permutation<7> p1 = Permutation<7>(tab);
  std::cout << "Voici une permutation: " << p1 << std::endl;
  std::pair<InvolutionNode *, InvolutionNode *> inv = robyInsertionCList(p1);
  std::cout << "Voici ses InvolutionsCLists:" << std::endl
            << inv.first << std::endl
            << inv.second << std::endl;

  InvolutionsVector invST = janvierInsertion(p1);
  std::cout << "Voici ses YFST:" << std::endl;
  display_involution(invST.first);
  std::cout << std::endl;
  display_involution(invST.second);
  std::cout
      << "\nEt finalement ses chemins dans le graphe de Young-Fibonacci:\n"
      << std::endl;
  auto r = permutationToChains(p1);
  display_chains(r);
  std::cout << "------------------------------------------------------"
            << std::endl;

  std::array<unsigned char, 8> t = {7, 3, 1, 5, 8, 4, 6, 2};
  Permutation<8> p2 = Permutation<8>(t);
  std::cout << "Voici une deuxieme permutation: " << p2 << std::endl;
  std::pair<InvolutionNode *, InvolutionNode *> inv2 = robyInsertionCList(p2);
  std::cout << "Voici ses InvolutionsCLists:" << std::endl
            << inv2.first << std::endl
            << inv2.second << std::endl;
  InvolutionsVector invST2 = janvierInsertion(p2);
  std::cout << "Voici ses YFST:" << std::endl;
  display_involution(invST2.first);
  std::cout << std::endl;
  display_involution(invST2.second);
  std::cout
      << "\nEt finalement ses chemins dans le graphe de Young-Fibonacci:\n"
      << std::endl;
  auto r2 = permutationToChains(p2);
  display_chains(r2);
  std::cout << "------------------------------------------------------"
            << std::endl;
  std::array<unsigned char, 32> data;
  data.fill(2);
  __m256i avx = _mm256_load_si256((__m256i *)&data[0]);

  int d = _mm256_extract_epi8(avx, 3);

  std::array<unsigned char, 32> res;
  memcpy(res.begin(), &avx, sizeof(res));

  for (int i = 0; i < 32; i++) {
    std::cout << static_cast<int>(res[i]) << " ";
  }
  return 0;
}