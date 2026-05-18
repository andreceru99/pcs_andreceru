#ifndef DIJKSTRA_HPP
#define DIJKSTRA_HPP

#include <map>
#include <set>
#include <queue>
#include <limits>
#include <vector>

#include "unidirected_graph.hpp"

// ho assunto che il peso di ogni arco sia 1


// restituisco una mappa con le distanze di ogni nodo dal nodo sorgente
std::map<int,int> dijkstra(const unidirected_graph& G, int source) {

    using dist_nodo = std::pair<int,int>;

    std::priority_queue<dist_nodo, std::vector<dist_nodo>, std::greater<dist_nodo>> pq;

    std::map<int,int> dist; // (distanza, nodo)
    std::set<int> visited;

    dist[source] =0;

    pq.push({0, source});

    //finché ho nodi da controllare
    while (!pq.empty()) {

        //restituisce la coppia con distanza minore
        int u =pq.top().second;

        pq.pop();

        //evito doppie visite dello stesso nodo
        if(visited.count(u)) {
            continue; //salto al prossimo giro del ciclo while
        }

        // altrimenti aggiungo ai visitati
        visited.insert(u);

        // ciclo per i nodi vicini
        for (int v: G.neighbours(u)) {
            int new_distance = dist[u] +1;

            /*aggiorno la distanza di v se:
            - v non ha ancora una distanza
            - ho trovato una distanza migliore*/
            if (!dist.count(v) || new_distance < dist[v]) {
                dist[v] = new_distance;
                pq.push({new_distance, v});
            }
        }

    }
    return dist;
}




#endif