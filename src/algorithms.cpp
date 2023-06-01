#include "../include/algorithms.hpp"
#include "../include/involutionChainList.hpp"

void insertCList(unsigned char key, unsigned char element, InvolutionsCLists &prevs,
            InvolutionsCLists &act, InvolutionsCLists &heads) {
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
        insertCList(key, temp, prevs, act, heads);
      }
    }
  } else {
    insertNode(prevs.first, heads.first, {element, 0});
    insertNode(prevs.second, heads.second, {key, 0});
  }
}