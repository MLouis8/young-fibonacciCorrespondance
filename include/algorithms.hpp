#include "involution.hpp"
#include "permutation.hpp"
#include <utility>

std::pair<InvolutionNode *, InvolutionNode *>
insert(unsigned char key, unsigned char element, InvolutionNode *prev1,
       InvolutionNode *prev2, InvolutionNode act1, InvolutionNode act2,
       std::pair<InvolutionNode*, InvolutionNode*> heads);

template <size_t T>
std::pair<InvolutionNode *, InvolutionNode *> robyInsertion(Permutation<T> p) {
  std::pair<InvolutionNode *, InvolutionNode *> heads = {
      insertNode(nullptr, nullptr, {p[1], 0}),
      insertNode(nullptr, nullptr, {1, 0})};
  for (unsigned char k = 2; k <= p.get_size(); k++) {
    std::cout << heads.first << std::endl << heads.second << std::endl;
    heads = insert(k, p[k], nullptr, nullptr, heads.first,
                   heads.second, heads);
  }
  return heads;
}
