#ifndef IS_SORTED_HPP
#define IS_SORTED_HPP

#include <vector>

// codice per verificare se un oggetto è ordinato

template<typename T>
bool is_sorted(const std::vector<T>& v) {
    for (size_t i = 1; i <v.size();i++) {
        if (v[i] < v[i-1]) {
            return false;
        }
    }
    return true;
}

#endif