#include "include/involution.hpp"
#include <array>
#include <ostream>

InvolutionNode *insertNode(InvolutionNode *prev, InvolutionNode *head,
                           std::array<unsigned char, 2> value) {
  InvolutionNode *newNode = new InvolutionNode;
  newNode->val = value;
  if (prev) {
    newNode->next = prev->next;
    prev->next = newNode;
    return newNode;
  }
  newNode->next = head;
  head = newNode;
  return head;
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