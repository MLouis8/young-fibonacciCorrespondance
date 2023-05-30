#include "include/involution.hpp"
#include <array>
#include <cstddef>
#include <iostream>

void insertNode(InvolutionNode *&prev, InvolutionNode *&head,
                           std::array<unsigned char, 2> value) {
  InvolutionNode *newNode = new InvolutionNode(value);
  if (prev) {
    newNode->next = prev->next;
    prev->next = newNode;
    return;
  }
  newNode->next = head;
  prev = newNode;
  head = newNode;
}

InvolutionNode *buildInvolution(std::vector<std::array<unsigned char, 2>> tab) {
  InvolutionNode *prev = nullptr;
  InvolutionNode *head = nullptr;
  for (size_t i = 0; i < tab.size(); i++) {
    insertNode(prev, head, tab[i]);
    while (prev->next) prev = prev->next;
  }
  return head;
}

bool operator==(InvolutionNode invA, InvolutionNode invB) {
  if (invA.val != invB.val)
    return false;
  while (invA.next) {
    if (not invB.next)
      return false;
    invA = *invA.next;
    invB = *invB.next;
    if (invA.val != invB.val)
      return false;
  }
  if (invB.next)
    return false;
  return true;
}

std::ostream &operator<<(std::ostream &os, InvolutionNode *inv) {
  InvolutionNode *act = inv;
  os << "[ ";
  while (act) {
    os << static_cast<int>(act->val[1]) << " ";
    act = act->next;
  }
  act = inv;
  os << "]" << std::endl << "[ ";
  while (act) {
    os << static_cast<int>(act->val[0]) << " ";
    act = act->next;
  }
  os << "]" << std::endl;
  return os;
}