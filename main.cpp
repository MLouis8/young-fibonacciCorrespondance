#include "algorithms.cpp"
#include "involution.cpp"

int main(int, char **) {
  std::cout << "Hello, world!\n";
  std::array<unsigned char, 7> tab = {2, 7, 1, 5, 6, 4, 3};
  Permutation<7> p1 = Permutation<7>(tab);
  std::cout << "Voici la permutation: " << p1 << std::endl;
  std::vector<int> t;
  // std::pair<Involution, Involution> involutionsRoby = robyInsertion(p1);
  //  display_tab(involutionsRoby.first);
  //  display_tab(involutionsRoby.second);

  //   InvolutionNode *head = insertNode(nullptr, nullptr, {0, 0});
  //   InvolutionNode *tail = insertNode(head, head, {2, 0});
  //   tail = insertNode(tail, head, {3, 0});
  //   tail = insertNode(tail, head, {4, 0});
  //   tail = insertNode(head, head, {54, 54});
  //   while(tail->next) tail = tail->next;
  //   tail = insertNode(tail, head, {5, 0});
  //   std::cout << head;

  return 0;
}
