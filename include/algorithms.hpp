#include <tuple>
#include <utility>
#include <vector>
#include "permutation.hpp"

typedef std::vector<unsigned char> listeEntiere;
typedef std::pair<listeEntiere, listeEntiere> Involution;
typedef std::pair<listeEntiere, listeEntiere> Tableau;
typedef std::pair<listeEntiere, listeEntiere> STableau;
typedef std::vector<unsigned char> Chain;

void insert(unsigned char e, unsigned char key, Involution &inv1, Involution &inv2, size_t idC);

void shift(Involution &inv1, Involution &inv2, size_t start);

template<size_t T>
std::pair<Involution, Involution> robyInsertion(Permutation<T> p) {
    Involution inv1, inv2;
    for (unsigned char k = 1; k <= p.get_size(); k++) {
        unsigned char e = p[k];
        insert(e, k, inv1, inv2, 0);
    }
    std::pair<Involution, Involution> res (inv1, inv2);
    return res;
}

