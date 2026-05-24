#ifndef QUICKSORT_HPP
#define QUICKSORT_HPP

#include "partition.hpp"

#include <vector>

template<typename T>
void quicksort(std::vector<T>& A, int p, int r) {
    if(p<r) {

        // indice finale del pivot ottenuto dal partizionamento del vettore
        int q = partition(A, p, r);

        //ordinamento ricorsivo della parte sinistra
        quicksort(A, p , q-1);
        //ordinamento ricorsivo della parte destra
        quicksort(A, q+1 , r);

    }
}

#endif

// complessità media O(nlogn), se prendo come pivot l'ultimo elemento O(n^2)