#ifndef MERGESORT_HPP
#define MERGESORT_HPP

// algoritmo dle mergesort
#include "merge.hpp"

template<typename T>
void mergesort(std::vector<T>& A, int p, int r) {
    // solo se il vettore ha almeno 2 elementi
    if(p<r) {
        
        int q = (p + r) /2 ; //indice centrale
        
        mergesort(A, p, q); //ordino ricorsivmaente la parte sinistra
        mergesort(A,q+1, r); // ordino ricorsivamente la parte destra

        merge(A, p, q, r); // merge
    }
}

#endif

// complessità O(nlogn)