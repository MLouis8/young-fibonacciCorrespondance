#include "algorithms.cpp"
#include <array>
#include <iostream>
#include <vector>
#include "involution.cpp"

int main(int, char **) {
  std::cout << "Hello, world!\n";
  std::array<unsigned char, 7> tab = {2, 7, 1, 5, 6, 4, 3};
  Permutation<7> p1 = Permutation<7>(tab);
  std::cout << "Voici la permutation: " << p1 << std::endl;
  std::vector<int> t;
  //std::pair<Involution, Involution> involutionsRoby = robyInsertion(p1);
  // display_tab(involutionsRoby.first);
  // display_tab(involutionsRoby.second);


  return 0;
}
