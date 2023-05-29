#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "algorithms.cpp"
#include "involution.cpp"
#include "include/doctest.h"

TEST_CASE("test de l'insertion de Roby") {
  std::pair<InvolutionNode *, InvolutionNode *> heads_A = {
      insertNode(nullptr, nullptr, {2, 0}),
      insertNode(nullptr, nullptr, {1, 0})};

  heads_A =
      insert(2, 1, nullptr, nullptr, heads_A.first, heads_A.second, heads_A);
  CHECK(true);
  Permutation<3> p2 = Permutation<3>({2, 3, 1});
  std::pair<InvolutionNode *, InvolutionNode *> heads_B = {
      insertNode(nullptr, nullptr, {2, 0}),
      insertNode(nullptr, nullptr, {1, 0})};
  heads_B = robyInsertion(p2);
}