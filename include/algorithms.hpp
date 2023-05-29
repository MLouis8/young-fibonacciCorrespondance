#include "../display.cpp"
#include "permutation.hpp"
#include <tuple>
#include <utility>
#include <vector>

void insert(unsigned char e, unsigned char key, Involution &inv1,
            Involution &inv2, size_t idC);

void shift(Involution &inv1, Involution &inv2, size_t start);

template <size_t T>
std::pair<Involution, Involution> robyInsertion(Permutation<T> p) {
  Involution inv1, inv2;
  for (unsigned char k = 1; k <= p.get_size(); k++) {
    display_tab(inv1);
    std::cout << std::endl;
    display_tab(inv2);
    insert(p[k], k, inv1, inv2, 0);
  }
  std::pair<Involution, Involution> res(inv1, inv2);
  return res;
}
