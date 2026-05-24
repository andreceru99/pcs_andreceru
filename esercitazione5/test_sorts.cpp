#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <string>

#include "bubblesort.hpp"
#include "insertionsort.hpp"
#include "selectionsort.hpp"
#include "quicksort.hpp"
#include "mergesort.hpp"
#include "is_sorted.hpp"

int main()
{
    // questo mi serve per cambiare il seed dei numeri casuali ad ogni esecuzione
    srand(time(nullptr));
    /*test su vettori di interi*/
    for (int test = 0; test < 100; test++)
    {
        
        int size = rand() % 100 + 1; // dimensione casuale 1-100

        std::vector<int> v(size); // vettore 

        for (int i = 0; i < size; i++)
        {
            v[i] = rand() % 200 - 100; // riempio con numeri casuali tra -100 e 99
        }

        /*inizio test*/

        // test quicksort
        std::vector<int> quick_vec = v;
        quicksort(quick_vec, 0, quick_vec.size()-1);

        // check
        if (!is_sorted(quick_vec))
        {
            std::cout << "Errore quicksort\n";
            return 1;
        }

        // test bubblesort
        std::vector<int> bubble_vec = v;
        bubble_sort(bubble_vec);

        // check
        if (!is_sorted(bubble_vec))
        {
            std::cout << "Errore bubblesort\n";
            return 1;
        }

        // test insertionsort
        std::vector<int> insertion_vec = v;
        insertion_sort(insertion_vec);

        // check
        if (!is_sorted(insertion_vec))
        {
            std::cout << "Errore insertion_sort\n";
            return 1;
        }

        // test mergesort
        std::vector<int> merge_vec = v;
        mergesort(merge_vec, 0, merge_vec.size() -1);

        // check
        if (!is_sorted(merge_vec))
        {
            std::cout << "Errore mergesort\n";
            return 1;
        }

        // test selectionsort
        std::vector<int> selection_vec = v;
        selection_sort(selection_vec);

        // check
        if (!is_sorted(selection_vec))
        {
            std::cout << "Errore selection_sort\n";
            return 1;
        }

    }
    
    
    /*test sulle stringhe*/

    std::vector<std::string> words =
        {
            "Shelly",
            "Colt",
            "Spike",
            "Leon",
            "Colette",
            "Crow",
            "Sandy",
            "Surge",
            "Mortis",
            "Chester"
        };

    auto bubble_words = words;
    bubble_sort(bubble_words);

    if (!is_sorted(bubble_words))
    {
        std::cout << "Errore bubble_sort stringhe\n";
        return 1;
    }

    auto insertion_words = words;
    insertion_sort(insertion_words);

    if (!is_sorted(insertion_words))
    {
        std::cout << "Errore insertion_sort stringhe\n";
        return 1;
    }

    auto selection_words = words;
    selection_sort(selection_words);

    if (!is_sorted(selection_words))
    {
        std::cout << "Errore selection_sort stringhe\n";
        return 1;
    }

    auto quick_words = words;
    quicksort(quick_words, 0, quick_words.size() - 1);

    if (!is_sorted(quick_words))
    {
        std::cout << "Errore quicksort stringhe\n";
        return 1;
    }

    auto merge_words = words;
    mergesort(merge_words, 0, merge_words.size() - 1);

    if (!is_sorted(merge_words))
    {
        std::cout << "Errore mergesort stringhe\n";
        return 1;
    }
    std::cout << "Tutti i test passati\n";
    return 0;
}