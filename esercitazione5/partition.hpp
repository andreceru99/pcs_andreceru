#ifndef PARTITION_HPP
#define PARTITION_HPP

#include <vector>

 // implemento il partition da richiamare all'interno dle quicksort
template<typename T>

// p = inizio porzione di vettore
// r = fine porzione vettore

int partition(std::vector<T>& A, int p, int r) {
    T pivot = A[r]; // definisco il pivot com'è l'ultimo elemento 
    //

    int i = p - 1;

    for (int j = p; j < r; j++) {
        // se è minore del pivot
        if (A[j] <= pivot) {
            i++;
            std::swap(A[i], A[j]); // scamnbio 
        }
    }
    std::swap(A[i+1], A[r]);
    
    return i+1; // posizione finale corretta del pivot nel vettore ordinato
}

#endif