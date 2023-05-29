#pragma once

#include <array>
#include <cstddef>
#include <ostream>
#include <vector>

struct InvolutionNode {
  std::array<unsigned char, 2> val;
  InvolutionNode *next;
};

InvolutionNode *insertNode(InvolutionNode *prev, InvolutionNode **head,
                           std::array<unsigned char, 2>);

InvolutionNode *buildInvolution(std::vector<std::array<unsigned char, 2>> tab);

bool operator==(InvolutionNode invA, InvolutionNode invB);

std::ostream &operator<<(std::ostream &os, InvolutionNode *inv);