#ifndef UNIDIRECTED_GRAPH_HPP
#define UNIDIRECTED_GRAPH_HPP

// includo gli STL dle grafo
#include <set>
#include <map>

// classe degli archi
#include "unidirected_edge.hpp"

// classe che rappresenta un intero grafo
class unidirected_graph {

    private:
    // contenitore con gli archi del grafo
    std::set<unidirected_edge> edges_;  //variabile degli archi
    //lista di adiacenza del grafo
    std::map<int, std::set<int>> adjacency_; // archi adiacenit
    // questo serve per associare gli archi alla key (?)
    std::map<unidirected_edge, int> edge_to_number_;  // numero dell'arco
    // mappa inversa
    std::map<int, unidirected_edge> number_to_edge_; // arco associato al numero


    public:
    // costruttore
    unidirected_graph();
    // costruttore copia (per ©reare un nuovo grafo a partire da un altro)
    unidirected_graph(const unidirected_graph& other);
    // restituisce tutti i nodi vicini
    std::set<int> neighbours(int node) const;
    // aggiunge un nuovo arco
    void add_edge(const unidirected_edge& edge); //modifica il grafico non metto const
    // restituisce tutti gli archi 
    std::set<unidirected_edge> all_edges() const;
    // restituisce tutti i nodi
    std::set<int> all_nodes() const;
    // dato un arco restituisce il suo numero 
    int edge_number(const unidirected_edge& edge) const;
    // viceversa, restituisce l'arco corrispondende al numero
    unidirected_edge edge_at(int number) const;
    // operatore che restituisce la differenza tra due grafi
    unidirected_graph operator-(const unidirected_graph& other) const;




};

#endif