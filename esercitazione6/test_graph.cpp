#include <iostream>
#include <set>


#include "unidirected_graph.hpp"

int main() {
    // test creazione
    unidirected_graph g;

    // test aggiunta archi
    g.add_edge(unidirected_edge(1,2));
    g.add_edge(unidirected_edge(2,3));
    g.add_edge(unidirected_edge(1,4));
    g.add_edge(unidirected_edge(3,4));
    g.add_edge(unidirected_edge(4,3)); // testiamo anche un duplicato

    // test all_edges()
    std::cout << "Elenco degli archi:\n";
    auto edges = g.all_edges();

    for (const auto& edge: edges) {
        std::cout << edge << "\n";
    }

    // test all_nodes()
    std::cout << "Elenco dei nodi:\n";
    auto nodes = g.all_nodes();

    for (const auto& node: nodes) {
        std::cout << node << "\n";
    }
    // con la lista dei nodi poi posso controllare i vicini di ogni nodo: neighbours()
    for (const auto& node: nodes) {
        std::cout << "Tutti i vicini del nodo " << node << ":\n";
        auto neighbours  = g.neighbours(node);
        for (const auto& n : neighbours) {
            std::cout << n << "\n";
        }
    }

    // test edge_number()
    unidirected_edge e(1,4);

    std::cout << "Numero arco (1,4) = " << g.edge_number(e) <<"\n";
    
    // test edge_at()
    std::cout << "Arco numero 0: " << g.edge_at(0) << "\n";

    // test operator-
    // per questo verifichiamo prima il costruttore copia
    unidirected_graph g2(g);

    // e gli aggiungiamo degli archi
    g2.add_edge(unidirected_edge(4,7));
    g2.add_edge(unidirected_edge(3,6));
    g2.add_edge(unidirected_edge(3,4));
    
    std::cout << "Archi del grafo copiato:" << "\n";
    auto edges2 = g2.all_edges();
    
    for (const auto& edge : edges2) {
        std::cout << edge << "\n";
    }




    /*
    unidirected_graph diff = g - g2; // questo non restituisce niente perché g è contenuto in g2: serve fare g2-g

    std::cout << "Archi differenza:\n";

    for (const auto& edge: diff.all_edges()) {
        std::cout << edge << "\n";
    }
    */

    unidirected_graph diff = g2 - g;

        std::cout << "Archi differenza:\n";

    for (const auto& edge: diff.all_edges()) {
        std::cout << edge << "\n";
    }

    // verifico cosa succede se cerco i vicini di un arco inesistente
    auto test = g.neighbours(100);

    std::cout << "Vicini del nodo fittizio 100:\n";
    // se non ha vicini
    if (test.empty()) {
        //allora non esiste
        std::cout << "Nessun arco trovato\n";
    }
    else {
        for (const auto& edge : test) {
            std::cout << edge << "\n";
    }
    }



    return 0;
}