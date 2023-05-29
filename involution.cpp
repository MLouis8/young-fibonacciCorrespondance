#include "include/involution.hpp"
#include <array>
#include <cstddef>
#include <iostream>

InvolutionNode *insertNode(InvolutionNode *prev, InvolutionNode **head,
                           std::array<unsigned char, 2> value) {
  InvolutionNode *newNode = new InvolutionNode;
  newNode->val = value;
  if (prev) {
    newNode->next = prev->next;
    prev->next = newNode;
    return newNode;
  }
  newNode->next = *head;
  head = &newNode; // ne met pas a jour la valeur de head
  return newNode;
}

InvolutionNode *buildInvolution(std::vector<std::array<unsigned char, 2>> tab) {
  InvolutionNode *tail = nullptr;
  InvolutionNode *head = nullptr;
  for (size_t i = 0; i < tab.size(); i++) {
    tail = insertNode(tail, &head, tab[i]);
    continue;
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