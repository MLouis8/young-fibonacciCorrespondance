#include "../include/algorithms/robyInsertion.hpp"
#include "../include/involutionChainList.hpp"

void insertCList(unsigned char key, unsigned char element,
                 InvolutionsCLists &prevs, InvolutionsCLists &act,
                 InvolutionsCLists &heads) {
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

void insertFList(unsigned char key, unsigned char element, InvolutionsFList &l,
                FLIterator prev1, FLIterator prev2, FLIterator it1,
                FLIterator it2) {
  if (element < (*it1)[0]) {
    if ((*it1)[1] == 0) {
      (*it1)[1] = element;
      (*it2)[1] = key;
    } else {
      unsigned char temp = (*it1)[1];
      (*it1)[1] = element;
      if (std::next(it1) == l.first.end()) {
        l.first.insert_after(it1, {temp, 0});
        l.second.insert_after(it2, {key, 0});
      } else {
        insertFList(key, temp, l, it1, it2, std::next(it1), std::next(it2));
      }
    }
  } else {
    l.first.insert_after(prev1, {element, 0});
    l.second.insert_after(prev2, {key, 0});
  }
}

void insertList(unsigned char key, unsigned char element, InvolutionsList &l,
                LIterator it1, LIterator it2) {
  if (element < (*it1)[0]) {
    if ((*it1)[1] == 0) {
      (*it1)[1] = element;
      (*it2)[1] = key;
    } else {
      unsigned char temp = (*it1)[1];
      (*it1)[1] = element;
      if (it1 == l.first.end()) {
        l.first.push_back({temp, 0});
        l.second.push_back({key, 0});
      } else {
        insertList(key, temp, l, std::next(it1), std::next(it2));
      }
    }
  } else {
    l.first.insert(it1, {element, 0});
    l.second.insert(it2, {key, 0});
  }
}

void insertVector(unsigned char key, unsigned char element,
                  InvolutionsVector &v, size_t id) {
  if (element < v.first[id][0]) {
    if (v.first[id][1] == 0) {
      v.first[id][1] = element;
      v.second[id][1] = key;
    } else {
      unsigned char temp = v.first[id][1];
      v.first[id][1] = element;
      if (id + 1 == v.first.size()) {
        v.first.push_back({temp, 0});
        v.second.push_back({key, 0});
      } else {
        insertVector(key, temp, v, id + 1);
      }
    }
  } else {
    v.first.insert(v.first.begin() + id, {element, 0});
    v.second.insert(v.second.begin() + id, {key, 0});
  }
}