#ifndef DEPINA_HPP
#define DEPINA_HPP


#include <vector>
#include <limits>
#include <queue>
#include <algorithm>
#include <stdexcept>


#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include "bool_vector.hpp"
#include "graph_visit_update.hpp"

// funzione che inizializza i vettori S
template<typename I>
std::vector<bool_vector> initialize_S_vectors(
    const unidirected_graph<I>& G, // grafo completo
    const unidirected_graph<I>& cotree // coalbero
)
{
    std::vector<bool_vector> S; // Vettore di vettori booleani

    int m = static_cast<int>(G.all_edges().size());

    for (const auto& e : cotree.all_edges())
    {
        int id = G.edge_number(e);

        if (id == -1)
        {
            throw std::runtime_error("Arco del coalbero non trovato nel grafo originale");
        }

        bool_vector s(m);
        s.set(id, 1);

        S.push_back(s);
    }

    return S;
};


// v0 -> v0 = 2 * i, v1 = 2 * i+1
int plus_vertex(int v) {
    return 2*v;
}
int minus_vertex(int v) {
    return 2*v +1;
}
int original_vertex(int duplicated_vertex) {
    return duplicated_vertex / 2;
}


struct depina_cycle {
    bool_vector incidence;
    std::vector<int> vertices;
};


depina_cycle find_minimal_cycle(
    const unidirected_graph<int>& G,
    const bool_vector& S // vettore booleano
) {

    // dimensione C
    int m = G.all_edges().size();
    // definisco il grafo ausiliario G2
    unidirected_graph<int> G2;


    for (int i = 0; i < G.all_edges().size(); i++) {
        // modificare il for con il numero di archi presenti e ciclare su i
        unidirected_edge e = G.edge_at(i);

        int u = e.from();
        int v = e.to();

        if (S[i] == 1) {
        G2.add_edge(unidirected_edge<int>(plus_vertex(u), minus_vertex(v)));
        G2.add_edge(unidirected_edge<int>(minus_vertex(u), plus_vertex(v)));
        }
        else if (S[i] == 0) {
        G2.add_edge(unidirected_edge<int>(plus_vertex(u), plus_vertex(v)));
        G2.add_edge(unidirected_edge<int>(minus_vertex(u), minus_vertex(v)));
        }
    }

    for (int i = 0; i < G.all_edges().size(); i++) {
        unidirected_edge e = G.edge_at(i);
        int u = e.from();
        int v = e.to();
        if (S[i] == 1) {
        G2.add_edge(unidirected_edge<int>(plus_vertex(u), minus_vertex(v)));
        G2.add_edge(unidirected_edge<int>(minus_vertex(u), plus_vertex(v)));
        }
        else if (S[i] == 0) {
        G2.add_edge(unidirected_edge<int>(plus_vertex(u), plus_vertex(v)));
        G2.add_edge(unidirected_edge<int>(minus_vertex(u), minus_vertex(v)));
        }
    }

    // usiamo bfs per trovare il cammino minimo
    std::vector<int> best_path;
    int best_lenght = std::numeric_limits<int>::max(); // inizializziamo la lunghezza migliore come massima

    for (int v :G.all_nodes()) {
        int source = plus_vertex(v);
        int target = minus_vertex(v);
        
        std::vector<int> path = graph_visit_updated(G2,source, target); // gli diamo v+ e v- e troviamo il path migliore

        if (!path.empty() && static_cast<int>(path.size()) < best_lenght) {
            best_path = path;
            best_lenght = static_cast<int>(path.size());
        }

    }
    if (best_path.empty()) {
        throw std::runtime_error("Nessun ciclo trovato");
    }

    bool_vector C(m);
    std::vector<int> cycle_vertices;

    for (int i = 0; i < static_cast<int>(best_path.size()); i++) {
        int v = original_vertex(best_path[i]);

        if (cycle_vertices.empty() || cycle_vertices.back() != v) {
            cycle_vertices.push_back(v);
        }
    }

    if (!cycle_vertices.empty() && cycle_vertices.front() == cycle_vertices.back()) {
        cycle_vertices.pop_back();
    }

    for (int i = 0; i + 1 < static_cast<int>(best_path.size()); i++) {
        int a = best_path[i];
        int b = best_path[i + 1];

        int u = original_vertex(a);
        int v = original_vertex(b);

        int id = G.edge_number(unidirected_edge<int>(u, v));

        if (id == -1) {
            throw std::runtime_error("Arco non trovato durante la ricostruzione del ciclo");
        }

        C.set(id, 1);
    }

    return {C, cycle_vertices};
}


std::vector<depina_cycle> de_pina(
    const unidirected_graph<int> G,
    std::vector<bool_vector> S
) {
    int k = static_cast<int>(S.size());
    std::vector<depina_cycle> cycles(k);
    std::vector<bool_vector> C(k); // base di vettori booleani
    for (int i = 0; i < k; ++i) {

        //aggiungi C[i] alla base;
        cycles[i] = find_minimal_cycle(G, S[i]);
        C[i] = cycles[i].incidence;

        for (int j = i + 1; j < k; ++j) {
            if (C[i].prod_scal_mod2(S[j]) == 1) {
                S[j].xor_with(S[i]); // la funzione xor_with modifica già internamente S[j], quindi non c'è bisogno di sostuirlo
            }
        }
    }
    return cycles;
}


#endif