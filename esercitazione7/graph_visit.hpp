#ifndef GRAPH_VISIT_HPP
#define GRAPH_VISIT_HPP

#include <set>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"


template<typename Container> 
unidirected_graph graph_visit(const unidirected_graph& G, int source, Container& container) {

    //albero della visita
    unidirected_graph tree;

    // nodi visitati
    std::set<int> visited;

    //inizializzo il nodo sorgente
    visited.insert(source);

    //inserisco il nodo nel contenitore
    container.put(source);

    // algoritmo
    while(!container.empty()) {

        // estraggo un nodo
        int u = container.get();

        //std::cout << u << " ";

        //visito i nodi vicini
        for (int v : G.neighbours(u)) {

            // verifico che il nodo non sia stato già visitato
            if (visited.count(v) == 0) {
                //lo aggiungo ai visitati
                visited.insert(v);

                //aggiunngo l'arco all'albero
                tree.add_edge(unidirected_edge(u,v));

                // inserisco il nodo nel container
                container.put(v);
            }
        }

    }



    return tree;
}








#endif