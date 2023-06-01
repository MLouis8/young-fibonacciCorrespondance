#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "../include/involutionChainList.hpp"
#include "../include/permutation.hpp"

#include "../src/algorithms.cpp"
#include "../src/involutionChainList.cpp"

Permutation<3> p1 = Permutation<3>({2, 3, 1});
Permutation<3> p2 = Permutation<3>({1, 3, 2});
Permutation<5> p3 = Permutation<5>({5, 3, 4, 1, 2});
Permutation<5> p4 = Permutation<5>({5, 2, 1, 3, 4});

TEST_CASE("Test insertion de Roby") {
  InvolutionsCLists heads_A = robyInsertionCList(p1);
  InvolutionNode *res_A_first = buildInvolution({{3, 1}, {2, 0}});
  InvolutionNode *res_A_second = buildInvolution({{2, 3}, {1, 0}});
  CHECK(*heads_A.first == *res_A_first);
  CHECK(*heads_A.second == *res_A_second);

  InvolutionsCLists heads_B = robyInsertionCList(p2);
  InvolutionNode *res_B_first = buildInvolution({{3, 2}, {1, 0}});
  InvolutionNode *res_B_second = buildInvolution({{2, 3}, {1, 0}});
  CHECK(*heads_B.first == *res_B_first);
  CHECK(*heads_B.second == *res_B_second);

  InvolutionsCLists heads_C = robyInsertionCList(p3);
  InvolutionNode *res_C_first = buildInvolution({{5, 2}, {4, 1}, {3, 0}});
  InvolutionNode *res_C_second = buildInvolution({{1, 2}, {4, 5}, {3, 0}});
  CHECK(*heads_C.first == *res_C_first);
  CHECK(*heads_C.second == *res_C_second);

  InvolutionsCLists heads_D = robyInsertionCList(p4);
  InvolutionNode *res_D_first = buildInvolution({{5, 4}, {3, 0}, {2, 1}});
  InvolutionNode *res_D_second = buildInvolution({{1, 2}, {5, 0}, {3, 4}});
  CHECK(*heads_D.first == *res_D_first);
  CHECK(*heads_D.second == *res_D_second);
}

TEST_CASE("Test insertion Janvier") {
  InvolutionsVector vector_A = janvierInsertion(p1);
  InvolutionsVector res_A = {{{1, 3}, {2, 0}}, {{2, 3}, {1, 0}}};
  CHECK(vector_A.first == res_A.first);
  CHECK(vector_A.second == res_A.second);

  InvolutionsVector vector_B = janvierInsertion(p2);
  InvolutionsVector res_B = {{{2, 3}, {1, 0}}, {{2, 3}, {1, 0}}};
  CHECK(vector_B.first == res_B.first);
  CHECK(vector_B.second == res_B.second);

  InvolutionsVector vector_C = janvierInsertion(p3);
  InvolutionsVector res_C = {{{2, 5}, {1, 4}, {3, 0}},
                             {{1, 5}, {3, 4}, {2, 0}}};
  CHECK(vector_C.first == res_C.first);
  CHECK(vector_C.second == res_C.second);

  InvolutionsVector vector_D = janvierInsertion(p4);
  InvolutionsVector res_D = {{{4, 5}, {3, 0}, {1, 2}},
                             {{1, 5}, {4, 0}, {2, 3}}};
  CHECK(vector_D.first == res_D.first);
  CHECK(vector_D.second == res_D.second);
}