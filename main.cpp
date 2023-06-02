#include "include/algorithms.hpp"
#include "include/involutionChainList.hpp"
#include "src/algorithms.cpp"
#include "src/involutionChainList.cpp"
#include <array>
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
  std::cout << "Voici ses SYFT:" << std::endl;
  display_involution(invST.first);
  std::cout << std::endl;
  display_involution(invST.second);
  auto r = permutationToChains(p1);
  display_chains(r);

  std::cout << "------------------------------------------------------"
            << std::endl;
  return 0;
}