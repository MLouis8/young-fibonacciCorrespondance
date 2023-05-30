#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "../include/involution.hpp"
#include "../include/permutation.hpp"

#include "../src/algorithms.cpp"
#include "../src/involution.cpp"

Permutation<3> p1 = Permutation<3>({2, 3, 1});
Permutation<3> p2 = Permutation<3>({1, 3, 2});
Permutation<5> p3 = Permutation<5>({5, 3, 4, 1, 2});
Permutation<5> p4 = Permutation<5>({5, 2, 1, 3, 4});

TEST_CASE("Test insertion de Roby") {
  Involutions heads_A = robyInsertion(p1);
  InvolutionNode *res_A_first = buildInvolution({{3, 1}, {2, 0}});
  InvolutionNode *res_A_second = buildInvolution({{2, 3}, {1, 0}});
  CHECK(*heads_A.first == *res_A_first);
  CHECK(*heads_A.second == *res_A_second);

  Involutions heads_B = robyInsertion(p2);
  InvolutionNode *res_B_first = buildInvolution({{3, 2}, {1, 0}});
  InvolutionNode *res_B_second = buildInvolution({{2, 3}, {1, 0}});
  CHECK(*heads_B.first == *res_B_first);
  CHECK(*heads_B.second == *res_B_second);

  Involutions heads_C = robyInsertion(p3);
  InvolutionNode *res_C_first = buildInvolution({{5, 2}, {4, 1}, {3, 0}});
  InvolutionNode *res_C_second = buildInvolution({{1, 2}, {4, 5}, {3, 0}});
  CHECK(*heads_C.first == *res_C_first);
  CHECK(*heads_C.second == *res_C_second);

  Involutions heads_D = robyInsertion(p4);
  InvolutionNode *res_D_first = buildInvolution({{5, 4}, {3, 0}, {2, 1}});
  InvolutionNode *res_D_second = buildInvolution({{1, 2}, {5, 0}, {3, 4}});
  CHECK(*heads_D.first == *res_D_first);
  CHECK(*heads_D.second == *res_D_second);
}

TEST_CASE("Test insertion Janvier") {
  Involutions heads_A = janvierInsertion(p1);
  InvolutionNode *res_A_first = buildInvolution({{1, 3}, {2, 0}});
  InvolutionNode *res_A_second = buildInvolution({{2, 3}, {1, 0}});
  CHECK(*heads_A.first == *res_A_first);
  CHECK(*heads_A.second == *res_A_second);

  Involutions heads_B = janvierInsertion(p2);
  InvolutionNode *res_B_first = buildInvolution({{2, 3}, {1, 0}});
  InvolutionNode *res_B_second = buildInvolution({{2, 3}, {1, 0}});
  CHECK(*heads_B.first == *res_B_first);
  CHECK(*heads_B.second == *res_B_second);

  Involutions heads_C = janvierInsertion(p3);
  InvolutionNode *res_C_first = buildInvolution({{2, 5}, {1, 4}, {3, 0}});
  InvolutionNode *res_C_second = buildInvolution({{1, 5}, {3, 4}, {2, 0}});
  CHECK(*heads_C.first == *res_C_first);
  CHECK(*heads_C.second == *res_C_second);

  Involutions heads_D = janvierInsertion(p4);
  InvolutionNode *res_D_first = buildInvolution({{4, 5}, {3, 0}, {1, 2}});
  InvolutionNode *res_D_second = buildInvolution({{1, 5}, {4, 0}, {2, 3}});
  CHECK(*heads_D.first == *res_D_first);
  CHECK(*heads_D.second == *res_D_second);
}