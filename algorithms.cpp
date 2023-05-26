#include "include/algorithms.hpp"

void insert(unsigned char e, unsigned char key, Involution &inv1, Involution &inv2, size_t idC) {
    if (inv1.first.size() <= idC) {
        inv1.first.push_back(e);
        inv1.first.push_back(0);
        inv1.second.push_back(key);
        inv1.second.push_back(0);
    } else if (e > inv1.first[idC]) {
        shift(inv1, inv2, idC);
        inv1.first[idC] = e;
        inv2.first[idC] = key;
    } else {
        if (inv1.second[idC]) {
                unsigned char tmp = inv1.second[idC];
                inv1.second[idC] = e;
                insert(tmp, key, inv1, inv2, idC+1);
        } else {
                inv1.second[idC] = e;
                inv2.second[idC] = key;
        }
    }
}

void shift(Involution &inv1, Involution &inv2, size_t start) {
    inv1.first.push_back(inv1.first.back());
    inv1.second.push_back(inv1.second.back());
    inv2.first.push_back(inv2.first.back());
    inv2.second.push_back(inv2.second.back());
    inv1.first[inv1.first.size()-2] = 0;
    inv1.second[inv1.second.size()-2] = 0;
    inv2.first[inv2.first.size()-2] = 0;
    inv2.second[inv2.second.size()-2] = 0;
    for (size_t i = inv1.first.size()-2; i > start; i--) {
        inv1.first[i] = inv1.first[i-1];
        inv1.second[i] = inv1.second[i-1];
        inv2.first[i] = inv2.first[i-1];
        inv2.second[i] = inv2.second[i-1];
    }
}
