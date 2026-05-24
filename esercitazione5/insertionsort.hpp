#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

// rifaccio l'algoritmo perché lo voglio implementare come file .hpp

#include <vector>
#include <utility>

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
     // vettore di due elementi già ordinato
    if (vec.size() < 2) {
        return;
    }

    // dal secondo elemento
    for (size_t j = 1; j < vec.size(); ++j) {
        // 
        T key = vec[j];
        int i = static_cast<int>(j) - 1;

        // finchè troviamo elementi più grandi della key li spostiamo verso destra
        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            --i;
        }

        // mettiamo la key nella posizione corretta
        vec[i + 1] = key;
    }
}

#endif


//complessità O(n^2)