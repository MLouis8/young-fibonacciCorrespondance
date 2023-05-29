#include <array>
#include <cstddef>
#include <ostream>

struct InvolutionNode {
  std::array<unsigned char, 2> val;
  InvolutionNode *next;

  InvolutionNode *insertNode(InvolutionNode *prev, InvolutionNode *head,
                             std::array<unsigned char, 2>);
};

std::ostream &operator<<(std::ostream &os, InvolutionNode *inv);