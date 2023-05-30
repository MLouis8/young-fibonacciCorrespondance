#include "include/involution.hpp"
#include "src/algorithms.cpp"
#include "src/involution.cpp"
#include <array>
#include <ostream>

int main(int, char **) {
  std::cout << "Hello, world!\n";
  std::array<unsigned char, 7> tab = {2, 7, 1, 5, 6, 4, 3};
  Permutation<7> p1 = Permutation<7>(tab);
  std::cout << "Voici une permutation: " << p1 << std::endl;
  std::vector<int> t;

  std::pair<InvolutionNode *, InvolutionNode *> inv = robyInsertion(p1);
  std::cout << "Voici ses involutions:" << std::endl
            << inv.first << std::endl
            << inv.second << std::endl;

  return 0;
}
