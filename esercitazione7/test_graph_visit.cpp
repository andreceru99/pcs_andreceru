#include <iostream>

#include "fifo.hpp"
#include "lifo.hpp"

#include "graph_visit.hpp"
#include "recursive_dfs.hpp"

//volevo vedere l'ordine di visita dei nodi senza sporcare graph_visit.hpp
template<typename Container> 
void visit_order(const unidirected_graph& G, int source, Container& container) {
    std::set<int> visited;

    visited.insert(source);
    container.put(source);

    while (!container.empty()) {
        int u = container.get();

        std::cout << u << " ";

        for (int v : G.neighbours(u)) {
            if (visited.count(v) == 0) {
                visited.insert(v);
                container.put(v);
            }
        }
        std::cout << "\n";
    }
}



int main() {
    
    //creo il grafo
    unidirected_graph G;


    /* 
    grafo visto a lezione, ma non si vede bene la differenza
    G.add_edge(unidirected_edge(1,2));
    G.add_edge(unidirected_edge(1,3));
    G.add_edge(unidirected_edge(3,4));
    G.add_edge(unidirected_edge(3,5));
    G.add_edge(unidirected_edge(4,5));
    G.add_edge(unidirected_edge(4,6));
    G.add_edge(unidirected_edge(5,6));
    */

    //aggiungo gli archi
    G.add_edge(unidirected_edge(1,2));
    G.add_edge(unidirected_edge(1,3));

    G.add_edge(unidirected_edge(2,4));
    G.add_edge(unidirected_edge(2,5));

    G.add_edge(unidirected_edge(3,6));
    G.add_edge(unidirected_edge(3,7));

    G.add_edge(unidirected_edge(4,8));
    G.add_edge(unidirected_edge(4,9));

    G.add_edge(unidirected_edge(5,10));

    G.add_edge(unidirected_edge(7,11));
    G.add_edge(unidirected_edge(7,12));

    G.add_edge(unidirected_edge(12,13));

    //BFS
    fifo<int> q;

    auto bfs_tree = graph_visit(G,1,q); //albero risultante dalla visita
    
    std::cout << "BFS:\n"; 

    for (const auto& edge : bfs_tree.all_edges()) {
        std::cout << edge << "\n";

    }

    //DFS
    lifo<int> s;

    auto dfs_tree = graph_visit(G,1,s);

    std::cout << "\nDFS:\n";

    for (const auto& edge : dfs_tree.all_edges()) {
        std::cout << edge << "\n";

    }


    std::cout << "\nOrdine BFS:\n";

    fifo<int> q2;
    visit_order(G, 1, q2);

    std::cout << "\nOrdine DFS:\n";

    lifo<int> s2;
    visit_order(G, 1, s2);


    // Test DFS ricorsiva
    std::cout <<"\nDFS ricorsvia:\n";

    auto recursive_tree = recursive_dfs(G,1);

    for (const auto& edge : recursive_tree.all_edges()) {
        std::cout << edge << "\n";
    }


    return 0;
}






