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

  // InvolutionNode *res_A_first = buildInvolution({{1, 3}, {2, 0}});
  // InvolutionNode *res_A_second = buildInvolution({{2, 3}, {1, 0}});
  // InvolutionNode *res_B_first = buildInvolution({{2, 3}, {1, 0}});
  // InvolutionNode *res_B_second = buildInvolution({{2, 3}, {1, 0}});
  // InvolutionNode *res_C_first = buildInvolution({{2, 5}, {1, 4}, {3, 0}});
  // InvolutionNode *res_C_second = buildInvolution({{1, 5}, {3, 4}, {2, 0}});
  // InvolutionNode *res_D_first = buildInvolution({{4, 5}, {3, 0}, {1, 2}});
  // InvolutionNode *res_D_second = buildInvolution({{1, 5}, {4, 0}, {2, 3}});
  // std::cout << res_A_first << std::endl;
  // std::cout << res_A_second << std::endl;
  // std::cout << res_B_first << std::endl;
  // std::cout << res_B_second << std::endl;
  // std::cout << res_C_first << std::endl;
  // std::cout << res_C_second << std::endl;
  // std::cout << res_D_first << std::endl;
  // std::cout << res_D_second << std::endl;

  return 0;
}
