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

  // Permutation<5> p3 = Permutation<5>({5, 3, 4, 1, 2});
  // std::pair<InvolutionNode *, InvolutionNode *> heads_C = robyInsertion(p3);
  // InvolutionNode *res_C_first = buildInvolution({{5, 2}, {4, 1}, {3, 0}});
  // InvolutionNode *res_C_second = buildInvolution({{1, 2}, {4, 5}, {3, 0}});
  // std::cout << heads_C.first << heads_C.second;

  //   Permutation<3> p2 = Permutation<3>({1, 3, 2});
  //   std::pair<InvolutionNode *, InvolutionNode *> heads_B =
  //   robyInsertion(p2); std::cout << heads_B.first << heads_B.second; return
  //   0;
}
