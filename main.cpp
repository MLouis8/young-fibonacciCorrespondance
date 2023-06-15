#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <emmintrin.h>
#include <immintrin.h>
#include <iostream>
#include <smmintrin.h>
#include <tmmintrin.h>

#include "include/algorithms/janvierInsertion.hpp"
#include "include/algorithms/permuToChains.hpp"
#include "include/display.hpp"
#include "include/permutation.hpp"
#include "src/display.cpp"
#include "src/involutionChainList.cpp"
#include "src/permuToChainAVX.cpp"
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
  // __m128i testPerm = perm_ar16({4, 11, 7, 2, 6, 13, 16, 1, 5, 14, 12, 3, 9,
  // 15, 8, 10});
  // __m128i bl = permbl02;
  // //blacklist(bl, 2);
  // uint8_t c = _mm_popcnt_u32(_mm_movemask_epi8(bl));
  // std::cout << "\nc: " << static_cast<int>(c) << "\n";
  // std::cout << rule(permid, 1, bl, c);

  // auto res = permutationToChains(Permutation<16>({4, 11, 7, 2, 6, 13, 16, 1,
  // 5, 14, 12, 3, 9, 15, 8, 10})).first; for (auto e : res) {
  //   std::cout << " " << e;
  // }
  std::cout << "Correction:\n";
  std::array<unsigned char, 16> arr0 = {4, 11, 7,  2, 6, 13, 16, 1,
                                        5, 14, 12, 3, 9, 15, 8,  10};
  __m128i perm0 = perm_ar16(arr0);
  const ar16 arr1 = {5, 8, 7, 10, 13, 16, 4, 3, 1, 12, 11, 14, 6, 9, 2, 15};
  __m128i perm1 = perm_ar16(arr1);
  const ar16 arr2 = {6, 7, 11, 5, 1, 14, 10, 15, 16, 8, 9, 12, 3, 2, 13, 4};
  __m128i perm2 = perm_ar16(arr2);
  const ar16 arr3 = {2, 12, 13, 16, 11, 4, 10, 6, 14, 15, 9, 8, 3, 1, 7, 5};
  __m128i perm3 = perm_ar16(arr3);
  auto res = permutationToChains(Permutation<16>(arr0));
  for (auto i : res.first)
    std::cout << i << " ";
  std::cout << "\n\nEt le test:";
  auto tres = permutation16ToChainsAVX(perm0);
  for (auto i : tres.second)
    std::cout << i << " ";
  return 0;
}