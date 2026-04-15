#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdlib>
#include <ctime>
#include "timecounter.h"

template<typename T>
bool is_sorted(const std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return true;
    }

    for (size_t i = 1; i < vec.size(); ++i) {
        if (vec[i] < vec[i - 1]) {
            return false;
        }
    }

    return true;
}

template<typename T>
void insertion_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }

    for (size_t j = 1; j < vec.size(); ++j) {
        T key = vec[j];
        int i = static_cast<int>(j) - 1;

        while (i >= 0 && vec[i] > key) {
            vec[i + 1] = vec[i];
            --i;
        }

        vec[i + 1] = key;
    }
}

int main()
{
    srand(time(0));

    timecounter timer;
    double tempo_totale = 0.0;
    double tempo_totale_sort = 0.0;

    for (int i = 0; i < 100; ++i) {
        int dimensione = rand() % 91 + 10;

        std::vector<int> v;
        for (int j = 0; j < dimensione; ++j) {
            int valore = rand() % 2001 - 1000;
            v.push_back(valore);
        }

        std::vector<int> v_copy = v;

        timer.tic();
        insertion_sort(v);
        tempo_totale += timer.toc();

        timer.tic();
        std::sort(v_copy.begin(), v_copy.end());
        tempo_totale_sort += timer.toc();

        if (!is_sorted(v)) {
            std::cerr << "Errore: insertion_sort non ha ordinato correttamente il vettore di interi.\n";
            return EXIT_FAILURE;
        }

        if (!is_sorted(v_copy)) {
            std::cerr << "Errore: std::sort non ha ordinato correttamente il vettore di confronto.\n";
            return EXIT_FAILURE;
        }
    }

    std::cout << "Tempo totale per 100 ordinamenti con insertion_sort: "
              << tempo_totale << " secondi\n";
    std::cout << "Tempo totale per 100 ordinamenti con std::sort: "
              << tempo_totale_sort << " secondi\n";

    std::vector<std::string> parole = {
        "zaino", "quadro", "mela", "barca", "gatto",
        "cane", "fuoco", "ciao", "libro", "erba"
    };

    insertion_sort(parole);

    if (!is_sorted(parole)) {
        std::cerr << "Errore: insertion_sort non ha ordinato correttamente il vettore di stringhe.\n";
        return EXIT_FAILURE;
    }

    std::cout << "Test stringhe: SUPERATO!\n";

    return EXIT_SUCCESS;
}