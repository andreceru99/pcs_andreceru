#ifndef SELECTION_SORT_HPP
#define SELECTION_SORT_HPP

#include <vector>
#include <utility>

template<typename T>
void selection_sort(std::vector<T>& vec) {

    // se il vettore ha meno di 2 elmenti è già ordinato
    if (vec.size() < 2) {
        return;
    }

    // il ciclo esterno individua la posizione del minimo ©orrente
    for (size_t i = 0; i < vec.size() - 1; ++i) {
        
        size_t min = i; // inizializzo con il primo elemento

        // se ne trovo uno più piccolo aggiorno
        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }

        std::swap(vec[i], vec[min]); // scambio nella posizione trovata
    }
}

#endif


// complessità O(n^2)