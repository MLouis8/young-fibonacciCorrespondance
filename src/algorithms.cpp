#include "../include/algorithms.hpp"
#include "../include/involution.hpp"

void insert(unsigned char key, unsigned char element,
            std::pair<InvolutionNode *, InvolutionNode *> &prevs,
            std::pair<InvolutionNode *, InvolutionNode *> &act,
            std::pair<InvolutionNode *, InvolutionNode *> &heads) {
  if (element < act.first->val[0]) {
    if (not act.first->val[1]) {
      act.first->val[1] = element;
      act.second->val[1] = key;
    } else {
      unsigned char temp = act.first->val[1];
      act.first->val[1] = element;
      if (not act.first->next) {
        insertNode(act.first, heads.first, {temp, 0});
        insertNode(act.second, heads.second, {key, 0});
      } else {
        prevs = act;
        act.first = act.first->next;
        act.second = act.second->next;
        insert(key, temp, prevs, act, heads);
      }
    }
  } else {
    insertNode(prevs.first, heads.first, {element, 0});
    insertNode(prevs.second, heads.second, {key, 0});
  }
}