#ifndef GRAPH_VISIT_V2_HPP
#define GRAPH_VISIT_V2_HPP

#include <set>
#include <map>
#include <vector>
#include <algorithm>

#include "unidirected_edge.hpp"
#include "unidirected_graph.hpp"
#include "fifo.hpp"

// vogliamo implementare il bfs, partendo dal codice che abbiamo scritto per graph_visit, per trovare un cammino minimo
std::vector<int> graph_visit_updated(const unidirected_graph<int>& G, int source, int target) {

    // inizializziamo la coda vuota
    fifo<int> container;

    // nodi visitati
    std::set<int> visited;
    std::map<int,int> nodi_padre;

    //inizializzo il nodo sorgente
    visited.insert(source);
    nodi_padre[source] = -1;

    //inserisco il nodo nel contenitore
    container.put(source);

    // algoritmo
    while(!container.empty()) {

        // estraggo un nodo
        int u = container.get();

        if (u == target) {break;}

        //visito i nodi vicini
        for (int v : G.neighbours(u)) {

            // verifico che il nodo non sia stato già visitato
            if (visited.count(v) == 0) {
                //lo aggiungo ai visitati
                visited.insert(v);
                // aggiungiamo u ai nodi padre
                nodi_padre[v] = u;
                // inserisco il nodo nel container
                container.put(v);
            }
        }
    }


    //se il target non viene trovato usciamo 
    if (visited.count(target) == 0) {
        return {};
    }

    // ricostruisco al contrario il cammino trovato tramite nodi_padre
    std::vector<int> path;

    int current = target;

    // il ciclo si ferma quando current = -1, ovvero quando andiamo a cercare il nodo padre del nodo sorgente (definito all'inizio)
    while (current != -1) {
        path.push_back(current);
        current = nodi_padre[current];
    }

    std::reverse(path.begin(), path.end());

    return path;
}

#endif