#ifndef RECURSIVE_DFS_HPP
#define RECURSIVE_DFS_HPP

#include <set>
#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"


//funzione risorsiva

void recursive_dfs_visit(const unidirected_graph& G, int u, std::set<int>& visited, unidirected_graph& tree) {
    //segno il nodo come visitato
    visited.insert(u);

    //visito i vicini
    for (int v : G.neighbours(u)) {

        // controllo che il vicino non sia già stato visitato
        if (visited.count(v) == 0) {
            // aggiungo l'arco all'albero DFS
            tree.add_edge(unidirected_edge(u,v));

            //visita ricorsiva
            recursive_dfs_visit(G, v, visited, tree);
        }
    }
}

// funzione da richiamare

unidirected_graph recursive_dfs(const unidirected_graph& G, int source) {

    std::set<int> visited;
    unidirected_graph tree;

    //
    recursive_dfs_visit(G, source, visited, tree);

    return tree;
}


#endif