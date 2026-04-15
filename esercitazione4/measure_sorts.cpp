#include <iostream>
#include <vector>
#include <algorithm>
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
void bubble_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }

    for (size_t i = 0; i < vec.size() - 1; ++i) {
        for (size_t j = vec.size() - 1; j > i; --j) {
            if (vec[j] < vec[j - 1]) {
                std::swap(vec[j], vec[j - 1]);
            }
        }
    }
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

template<typename T>
void selection_sort(std::vector<T>& vec)
{
    if (vec.size() < 2) {
        return;
    }

    for (size_t i = 0; i < vec.size() - 1; ++i) {
        size_t min = i;

        for (size_t j = i + 1; j < vec.size(); ++j) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }

        std::swap(vec[i], vec[min]);
    }
}

int main()
{
    srand(time(0));

    std::cout << "n bubble_sort insertion_sort selection_sort std::sort\n";

    for (int n = 4; n <= 8192; n *= 2) {
        std::vector<int> v;

        for (int i = 0; i < n; ++i) {
            int valore = rand() % 2001 - 1000;
            v.push_back(valore);
        }

        std::vector<int> v_bubble = v;
        std::vector<int> v_insertion = v;
        std::vector<int> v_selection = v;
        std::vector<int> v_std = v;

        timecounter timer;

        timer.tic();
        bubble_sort(v_bubble);
        double tempo_bubble = timer.toc();

        timer.tic();
        insertion_sort(v_insertion);
        double tempo_insertion = timer.toc();

        timer.tic();
        selection_sort(v_selection);
        double tempo_selection = timer.toc();

        timer.tic();
        std::sort(v_std.begin(), v_std.end());
        double tempo_std = timer.toc();

        if (!is_sorted(v_bubble)) {
            std::cerr << "Errore: bubble_sort non ha ordinato correttamente.\n";
            return EXIT_FAILURE;
        }

        if (!is_sorted(v_insertion)) {
            std::cerr << "Errore: insertion_sort non ha ordinato correttamente.\n";
            return EXIT_FAILURE;
        }

        if (!is_sorted(v_selection)) {
            std::cerr << "Errore: selection_sort non ha ordinato correttamente.\n";
            return EXIT_FAILURE;
        }

        if (!is_sorted(v_std)) {
            std::cerr << "Errore: std::sort non ha ordinato correttamente.\n";
            return EXIT_FAILURE;
        }

        std::cout << n << " "
                  << tempo_bubble << " "
                  << tempo_insertion << " "
                  << tempo_selection << " "
                  << tempo_std << "\n";
    }

    return EXIT_SUCCESS;
}