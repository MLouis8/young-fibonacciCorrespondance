#include "algorithms.cpp"
#include "include/involution.hpp"
#include "involution.cpp"
#include <array>
#include <ostream>

int main(int, char **) {
  std::cout << "Hello, world!\n";
  std::array<unsigned char, 7> tab = {2, 7, 1, 5, 6, 4, 3};
  Permutation<7> p1 = Permutation<7>(tab);
  std::cout << "Voici une permutation: " << p1 << std::endl;
  std::vector<int> t;

  InvolutionNode *head = buildInvolution({{5, 2}, {4, 1}, {3, 0}});
  std::cout << "Voici une involution:" << std::endl << head << std::endl;

  return 0;
}
