#ifndef MERGE_HPP
#define MERGE_HPP

#include <vector>

// questa è la funzione merge che va richiamata nell'algoritmo per il mergesort


template<typename T>
void merge(std::vector<T>& A, int p, int q, int r) {

    int n1 = q - p +1; // dimensione sottovettore sinistro
    int n2 = r -q; // dimensione sottovettore destr

    // vettori temporanei
    std::vector<T> L(n1);
    std::vector<T> R(n2);

    // copia della parte sinistra
    for (int i = 0; i <n1; i++) {
        L[i] = A[p+i];
    }
    // copia della parte destra
    for (int j = 0; j<n2;j++) {
        R[j] = A[q+1 +j];
    }

    
    int i = 0; //indice di L
    int j = 0; //indice di R
    int k = p; //indice di vettore originale

    // confronto vettori temporanei, inserisce nel vettore originale quello più piccolo
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        }
        else {
            A[k] = R[j];
            j++;
        }
        k++;

    }
    
    // copia elementi rimasti in L e R
    while (i<n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j <n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}


#endif

// complessità O(n)