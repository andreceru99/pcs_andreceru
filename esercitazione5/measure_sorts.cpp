#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <algorithm>

#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"

using Clock  = std::chrono::high_resolution_clock;

int main() {
    srand(time(nullptr));

    const int size = 10000;// dimensione dei vettori

    const int num_vectors = 100; // numero di test

    //dataset di vettori casuali
    std::vector<std::vector<int>> dataset(num_vectors, std::vector<int>(size)); 


    //riempimento casuale
    for (int i =0; i <num_vectors; ++i) {
        for(int j = 0; j<size; ++j) {
            dataset[i][j] = rand() % 200 -100;

        }
    } 

    // test bubblesort 
    auto bubble_data = dataset;

    auto start = Clock::now();

    for (auto& v : bubble_data) {
        bubble_sort(v);
    }

    auto end = Clock::now();

    double bubble_time = std::chrono::duration<double, std::milli>(end - start).count();

    bubble_time /= num_vectors;

    std::cout << "Bubble sort medio: " << bubble_time << "ms\n";


    // test insertion sort
    auto insertion_data = dataset;

    start = Clock::now();

    for (auto& v : insertion_data)
    {
        insertion_sort(v);
    }

    end = Clock::now();

    double insertion_time =
        std::chrono::duration<double, std::milli>(end - start).count();

    insertion_time /= num_vectors;

    std::cout << "Insertion sort medio: "
              << insertion_time
              << " ms\n";

    // test selection sort

    auto selection_data = dataset;

    start = Clock::now();

    for (auto& v : selection_data)
    {
        selection_sort(v);
    }

    end = Clock::now();

    double selection_time =
        std::chrono::duration<double, std::milli>(end - start).count();

    selection_time /= num_vectors;

    std::cout << "Selection sort medio: "
              << selection_time
              << " ms\n";


    // test quicksort
    auto quick_data = dataset;

    start = Clock::now();

    for (auto& v : quick_data)
    {
        quicksort(v, 0, v.size() - 1);
    }

    end = Clock::now();

    double quick_time =
        std::chrono::duration<double, std::milli>(end - start).count();

    quick_time /= num_vectors;

    std::cout << "Quicksort medio: "
              << quick_time
              << " ms\n";


    // test mergesort
        auto merge_data = dataset;

    start = Clock::now();

    for (auto& v : merge_data)
    {
        mergesort(v, 0, v.size() - 1);
    }

    end = Clock::now();

    double merge_time =
        std::chrono::duration<double, std::milli>(end - start).count();

    merge_time /= num_vectors;

    std::cout << "Mergesort medio: "
              << merge_time
              << " ms\n";

    // test std::sort
    auto std_data = dataset;

    start = Clock::now();

    for (auto& v : std_data)
    {
        std::sort(v.begin(), v.end());
    }

    end = Clock::now();

    double std_time =
        std::chrono::duration<double, std::milli>(end - start).count();

    std_time /= num_vectors;

    std::cout << "std::sort medio: "
              << std_time
              << " ms\n";

    return 0;

}



/*
Output tempi misurati con size = 100:

Bubble sort medio: 0.0775346ms
Insertion sort medio: 0.0222304 ms
Selection sort medio: 0.0424375 ms
Quicksort medio: 0.00979833 ms
Mergesort medio: 0.0625571 ms
std::sort medio: 0.0020725 ms


Output tempi misurati con size = 10000:
Bubble sort medio: 310.791ms
Insertion sort medio: 79.9092 ms
Selection sort medio: 149.745 ms
Quicksort medio: 1.82893 ms
Mergesort medio: 4.14442 ms
std::sort medio: 0.0915912 ms
*/