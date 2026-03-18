# include <iostream>
#include <cmath>
#include <algorithm>

int main()
{
    static const int N = 10;
	double arr[N] = {3.2, 7.0, 1.5, 9.8, 4.1, 6.3, 2.7, 8.6, 0.9, 5.4}; 
    int count = 1;
    // ciclo che itera fintanto che avvengono scambi
    while (count > 0) {
        count = 0;

        for (int i = 0; i < N-1; i +=1) {
            // check: se l'elemento successivo è minore li scambio
            if (arr[i] > arr[i+1]) {
                double temp = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = temp;
                count += 1;
            }
        }
    }
    // stampa per controllo
    for (int i = 0; i < N; i += 1) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    return 0;
}