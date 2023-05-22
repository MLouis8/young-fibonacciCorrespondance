#include <algorithm>
#include <cmath>
#include <vector>
#include <map>

struct Permutation{
    std::map<int, int> permutation;
    std::vector<std::vector<int>> permutationMatrix;

    Permutation(std::vector<int> t) {
        int m = *std::min_element(t.begin(), t.end());
        for (int i = 0; i < t.size(); i++) {
            permutation[i + t[i]] = t[i];
        }
    }
};