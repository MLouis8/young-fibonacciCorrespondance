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

  std::cout << "---------------------------" << std::endl;
  InvolutionNode *res_A_first = buildInvolution({{1, 3}, {2, 0}});
  // InvolutionNode *res_A_second = buildInvolution({{2, 3}, {1, 0}});
  // InvolutionNode *res_B_first = buildInvolution({{2, 3}, {1, 0}});
  // InvolutionNode *res_B_second = buildInvolution({{2, 3}, {1, 0}});
  // InvolutionNode *res_C_first = buildInvolution({{2, 5}, {1, 4}, {3, 0}});
  // InvolutionNode *res_C_second = buildInvolution({{1, 5}, {3, 4}, {2, 0}});
  // InvolutionNode *res_D_first = buildInvolution({{4, 5}, {3, 0}, {1, 2}});
  // InvolutionNode *res_D_second = buildInvolution({{1, 5}, {4, 0}, {2, 3}});
  std::cout << res_A_first << std::endl;
  // std::cout << res_A_second << std::endl;
  // std::cout << res_B_first << std::endl;
  // std::cout << res_B_second << std::endl;
  // std::cout << res_C_first << std::endl;
  // std::cout << res_C_second << std::endl;
  // std::cout << res_D_first << std::endl;
  // std::cout << res_D_second << std::endl;
  Permutation<3> d1 = Permutation<3>({2, 3, 1});
  //Involutions resa = janvierInsertion(d1);
  //std::cout << resa.first;

  Involutions res;
  std::array<bool, 3> blacklist;
  std::fill(blacklist.begin(), blacklist.end(), false);
  Involutions last;
  Involutions heads;
  for (unsigned char i = d1.size(); i > 0; i--) {
    if (not blacklist[i]) {
      std::cout << "here " << static_cast<int>(i);
      std::pair<unsigned char, unsigned char> maxi =
          maxNotBlacklisted(d1, blacklist);
      blacklist[i] = true;
      if (maxi.first == i) {
        insertNode(last.first, heads.first, {d1.call(i), 0});
        insertNode(last.second, heads.second, {i, 0});
      } else {
        blacklist[maxi.second] = true;
        insertNode(last.first, heads.first, {d1.call(i), maxi.second});
        insertNode(last.second, heads.second, {maxi.first, i});
      }
    }
    if (last.first->next) {
      last.first = last.first->next;
      last.second = last.second->next;
    }
  }
  std::cout << res.first;
  return 0;
}
