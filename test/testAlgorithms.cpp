#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../include/doctest.h"
#include "../include/algorithms/permuToChains.hpp"
#include "../include/algorithms/janvierInsertion.hpp"

#include "../src/involutionChainList.cpp"
#include "../src/robyInsertion.cpp"

Permutation<3> p1 = Permutation<3>({2, 3, 1});
Permutation<3> p2 = Permutation<3>({1, 3, 2});
Permutation<5> p3 = Permutation<5>({5, 3, 4, 1, 2});
Permutation<5> p4 = Permutation<5>({5, 2, 1, 3, 4});
Permutation<4> p5 = Permutation<4>({3, 1, 4, 2});

TEST_CASE("Test insertion de Roby, version liste chainee") {
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

TEST_CASE("Test insertion de Roby, version vector") {
  InvolutionsVector vector_A = robyInsertionVector(p1);
  InvolutionsVector res_A = {{{3, 1}, {2, 0}}, {{2, 3}, {1, 0}}};
  CHECK(vector_A.first == res_A.first);
  CHECK(vector_A.second == res_A.second);

  InvolutionsVector vector_C = robyInsertionVector(p3);
  InvolutionsVector res_C = {{{5, 2}, {4, 1}, {3, 0}},
                             {{1, 2}, {4, 5}, {3, 0}}};
  CHECK(vector_C.first == res_C.first);
  CHECK(vector_C.second == res_C.second);
}

TEST_CASE("Test insertion de Roby, version std::list") {
  InvolutionsList list_A = robyInsertionList(p1);
  InvolutionsList res_A = {{{3, 1}, {2, 0}}, {{2, 3}, {1, 0}}};
  CHECK(list_A.first == res_A.first);
  CHECK(list_A.second == res_A.second);

  InvolutionsList list_C = robyInsertionList(p3);
  InvolutionsList res_C = {{{5, 2}, {4, 1}, {3, 0}}, {{1, 2}, {4, 5}, {3, 0}}};
  CHECK(list_C.first == res_C.first);
  CHECK(list_C.second == res_C.second);
}

TEST_CASE("Test insertion de Roby, version std::forward_list") {
  InvolutionsFList flist_A = robyInsertionFList(p1);
  InvolutionsFList res_A = {{{3, 1}, {2, 0}}, {{2, 3}, {1, 0}}};
  CHECK(flist_A.first == res_A.first);
  CHECK(flist_A.second == res_A.second);

  InvolutionsFList flist_C = robyInsertionFList(p3);
  InvolutionsFList res_C = {{{5, 2}, {4, 1}, {3, 0}}, {{1, 2}, {4, 5}, {3, 0}}};
  CHECK(flist_C.first == res_C.first);
  CHECK(flist_C.second == res_C.second);
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

TEST_CASE("Test algo permutation->chaines dans YF") {
  std::pair<std::array<size_t, 4>, std::array<size_t, 4>> chain_A =
      permutationToChains(p1);
  std::array<size_t, 4> res_A_first = {0, 1, 11, 21};
  std::array<size_t, 4> res_A_second = {0, 1, 2, 21};
  CHECK(chain_A.first == res_A_first);
  CHECK(chain_A.second == res_A_second);

  std::pair<std::array<size_t, 4>, std::array<size_t, 4>> chain_B =
      permutationToChains(p2);
  std::array<size_t, 4> res_B = {0, 1, 11, 21};
  CHECK(chain_B.first == res_B);
  CHECK(chain_B.second == res_B);

  std::pair<std::array<size_t, 6>, std::array<size_t, 6>> chain_C =
      permutationToChains(p3);
  std::array<size_t, 6> res_C_first = {0, 1, 2, 21, 211, 221};
  std::array<size_t, 6> res_C_second = {0, 1, 11, 21, 22, 221};
  CHECK(chain_C.first == res_C_first);
  CHECK(chain_C.second == res_C_second);

  std::pair<std::array<size_t, 6>, std::array<size_t, 6>> chain_D =
      permutationToChains(p4);
  std::array<size_t, 6> res_D_first = {0, 1, 2, 21, 22, 212};
  std::array<size_t, 6> res_D_second = {0, 1, 2, 12, 112, 212};
  CHECK(chain_D.first == res_D_first);
  CHECK(chain_D.second == res_D_second);

  std::pair<std::array<size_t, 5>, std::array<size_t, 5>> chain_E =
      permutationToChains(p5);
  std::array<size_t, 5> res_E_first = {0, 1, 2, 12, 22};
  std::array<size_t, 5> res_E_second = {0, 1, 11, 21, 22};
  CHECK(chain_E.first == res_E_first);
  CHECK(chain_E.second == res_E_second);
}