#include "include/algorithms.hpp"
#include "include/involution.hpp"

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
      if (not act1->next) {
        InvolutionNode *uTail1 = insertNode(act1, &heads.first, {temp, 0});
        InvolutionNode *uTail2 = insertNode(act2, &heads.second, {key, 0});
        return heads;
      }
      return insert(key, temp, act1, act2, act1->next, act2->next, heads);
    }
  } else {
    heads.first = insertNode(prev1, &heads.first, {element, 0});
    heads.second = insertNode(prev2, &heads.second, {key, 0});
  }
  return heads;
}