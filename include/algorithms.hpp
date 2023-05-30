#include "involution.hpp"
#include "permutation.hpp"
#include <utility>

void insert(unsigned char key, unsigned char element,
            std::pair<InvolutionNode *, InvolutionNode *> &prevs,
            std::pair<InvolutionNode *, InvolutionNode *> &act,
            std::pair<InvolutionNode *, InvolutionNode *> &heads);

template <size_t T>
std::pair<InvolutionNode *, InvolutionNode *> robyInsertion(Permutation<T> p) {
  std::pair<InvolutionNode *, InvolutionNode *> heads;
  std::pair<InvolutionNode *, InvolutionNode *> act;
  std::pair<InvolutionNode *, InvolutionNode *> prevs;
  insertNode(act.first, heads.first, {p[1], 0});
  insertNode(act.second, heads.second, {1, 0});
  for (unsigned char k = 2; k <= p.get_size(); k++) {
    act = heads;
    prevs = {nullptr, nullptr};
    insert(k, p[k], prevs, act, heads);
  }
  return heads;
}
