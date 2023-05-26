#include "../include/permutation.hpp"
#include <array>
#include <iostream>

int main() {
    std::array<unsigned char, 5> tab = {2, 3, 1, 5, 4};
    std::array<int, 2> t = {1, 0};
    Permutation<5> p = Permutation<5>(tab);
    std::cout << "hello world" << std::endl;
    std::cout << static_cast<int>(p[1]) << " then " << static_cast<int>(tab[1]) << " finally " << t[1] << std::endl;
    //std::cout << p; // marche pas
    return 0;
}
