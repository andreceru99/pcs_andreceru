#include <iostream>
#include <set>


#include "unidirected_edge.hpp"

int main()
{
    unidirected_edge e1(5,2);
    unidirected_edge e2(2,5);
    unidirected_edge e3(1,4);
    unidirected_edge e4(1,7);

// test costruttore
    std::cout << "e1 = " << e1 << "\n";
// test from() e to()
    std::cout << "from " << e1.from() << "\n";
    std::cout << "to " << e1.to() << "\n";
// test operator==
    if (e1 == e2) {
        std::cout << "operator== funziona" << "\n";
    }
    else {
        std::cout << "operator== NON funziona" << "\n";
    }
// test operator<
    if (e3 < e4) {
        std::cout << "operator< funziona" << "\n";
    }
    else {
        std::cout << "operator< NON funziona" << "\n";
    }
// test con std::set
    std::set<unidirected_edge> edges;

    edges.insert(unidirected_edge(5,2));
    edges.insert(unidirected_edge(2,5));
    edges.insert(unidirected_edge(1,4));
    edges.insert(unidirected_edge(3,6));
    // il set dovrebbe mantenere gli archi in maniera ordinata quindi sfrutta l'operatore <
    // utilizzo un clico for per stampare tutti gli elementi del contenitore
    // for (tipo variabile: contenitore)
    
    std::cout << "Archi nel set:" << "\n";
    for (const auto& edge : edges) {
        std::cout << edge << "\n";
    }
    // questo deve stampare una solta volta ogni elemento (ad esempio (2,5) e (5,2) sono lo stesso elemento)



    return 0;
}

