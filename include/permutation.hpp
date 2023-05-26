#include <array>
#include <cstddef>
#include <iostream>
#include <ostream>

template <size_t T>
struct Permutation {
    std::array<unsigned char, T> permutation;
    std::array<std::array<unsigned char, T>, T> matrix;

    Permutation(std::array<unsigned char, T> tab): permutation(tab) {}

    size_t get_size() { return permutation.size(); }

    unsigned char& operator[] (size_t id) {
        return permutation[id-1];
    }

    std::ostream& operator<<(std::ostream& os) {
        os << "[";
        for (size_t i = 0; i < permutation.size(); i++) os << permutation[i] << ", ";
        os << permutation.back() << "]" << std::endl;
        return os;
    }
};
