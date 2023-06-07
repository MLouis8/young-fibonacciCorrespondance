#pragma once

#include <array>
#include <ostream>
#include <vector>
#include <list>
#include <forward_list>

struct InvolutionNode {
  std::array<unsigned char, 2> val;
  InvolutionNode *next;
  InvolutionNode(const std::array<unsigned char, 2> t,
                 InvolutionNode *n = nullptr)
      : val{t}, next(n) {}
};

typedef std::pair<InvolutionNode *, InvolutionNode *> InvolutionsCLists;

void insertNode(InvolutionNode *&prev, InvolutionNode *&head,
                std::array<unsigned char, 2>);

InvolutionNode *buildInvolution(std::vector<std::array<unsigned char, 2>> tab);

bool operator==(InvolutionNode invA, InvolutionNode invB);

std::ostream &operator<<(std::ostream &os, InvolutionNode *inv);

typedef std::pair<std::vector<std::array<unsigned char, 2>>,
                  std::vector<std::array<unsigned char, 2>>>
    InvolutionsVector;

typedef std::pair<std::list<std::array<unsigned char, 2>>,
                  std::list<std::array<unsigned char, 2>>>
    InvolutionsList;

typedef std::_List_iterator<std::array<unsigned char, 2>> LIterator;


typedef std::pair<std::forward_list<std::array<unsigned char, 2>>,
                  std::forward_list<std::array<unsigned char, 2>>>
    InvolutionsFList;

typedef std::_Fwd_list_iterator<std::array<unsigned char, 2>> FLIterator;
