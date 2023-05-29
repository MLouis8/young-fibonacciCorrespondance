#include "include/algorithms.hpp"

std::pair<InvolutionNode *, InvolutionNode *>
insert(unsigned char key, unsigned char element, InvolutionNode *prev1,
       InvolutionNode *prev2, InvolutionNode *act1, InvolutionNode *act2,
       std::pair<InvolutionNode *, InvolutionNode *> heads) {
  if (element < act1->val[0]) {
    if (not act1->val[1]) {
      act1->val[1] = element;
      act2->val[1] = key;
    } else {
      unsigned char temp = act1->val[1];
      act1->val[1] = element;
      if (act1->next) {
        return insert(key, temp, act1, act2, act1->next, act2->next, heads);
      } else {
        InvolutionNode *a = insertNode(act1, heads.first, {0, 0});
        InvolutionNode *b = insertNode(act2, heads.second, {0, 0});
      }
    }
  } else {
    heads.first = insertNode(nullptr, heads.first, {element, 0});
    heads.second = insertNode(nullptr, heads.second, {key, 0});
  }
  return heads;
}