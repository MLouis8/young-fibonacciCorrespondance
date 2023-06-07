#include "include/algorithms.hpp"
#include "include/involutionChainList.hpp"
#include "include/permAVX.hpp"
#include "src/algorithms.cpp"
#include "src/involutionChainList.cpp"
#include <array>
#include <cstddef>
#include <forward_list>
#include <immintrin.h>
#include <iterator>
#include <numeric>
#include <ostream>

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

  return 0;
}