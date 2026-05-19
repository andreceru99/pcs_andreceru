#include "iostream"
#include "map"
#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include "dijkstra.hpp"



int main() {

    unidirected_graph G;

    G.add_edge(unidirected_edge(1,2));
    G.add_edge(unidirected_edge(1,3));
    G.add_edge(unidirected_edge(2,4));
    G.add_edge(unidirected_edge(3,5));
    G.add_edge(unidirected_edge(5,6));

    auto dist = dijkstra(G, 1);

    std::cout << "Distanza dal nodo 1:\n";

    for (const auto& pair : dist) {
        std::cout << "Nodo: " << pair.first << " distanza: " << pair.second << "\n";
    }

    return 0;
}



/*
output:
Nodo: 1 distanza: 0
Nodo: 2 distanza: 1
Nodo: 3 distanza: 1
Nodo: 4 distanza: 2
Nodo: 5 distanza: 2
Nodo: 6 distanza: 3
*/