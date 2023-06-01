#include "../include/algorithms.hpp"
#include "../include/involutionChainList.hpp"
#include <cstddef>

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

void insertVector(unsigned char key, unsigned char element, InvolutionsVector &v, size_t id) {
  if (element < v.first[id][0]) {
    if (v.first[id][1] == 0) {
      v.first[id][1] = element;
      v.second[id][1] = key;
    } else {
      unsigned char temp = v.first[id][1];
      v.first[id][1] = element;
      if (id+1 == v.first.size()) {
        v.first.push_back({temp, 0});
        v.second.push_back({key, 0});
      } else {
        insertVector(key, temp, v, id+1);
      }
    }
  } else {
    v.first.insert(v.first.begin()+id, {element, 0});
    v.second.insert(v.second.begin()+id, {key, 0});
  }
}