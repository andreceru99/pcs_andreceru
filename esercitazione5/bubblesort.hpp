#ifndef BUBBLE_SORT_HPP
#define BUBBLE_SORT_HPP

// rifaccio l'algoritmo perché lo voglio implementare come file .hpp

#include <vector>
#include <utility>

// da destra verso sinisrsta

template<typename T>
void bubble_sort(std::vector<T>& vec)
{
    // se il vettore ha meno di 2 elementi è già ordinato
    if (vec.size() < 2) {
        return;
    }
    // ad ogni iterazione sistema un elemento nella parte iniziale del vettore
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        // il ciclo interno scorre il vettore da destra a sinistra confrontando gli elementi adiacenti
        for (size_t j = vec.size() - 1; j > i; --j) {
            // confronta gli elementi consecutivi
            if (vec[j] < vec[j - 1]) {
                std::swap(vec[j], vec[j - 1]); //scambio
            }
        }
    }
}




#endif

// complessità O(n^2)