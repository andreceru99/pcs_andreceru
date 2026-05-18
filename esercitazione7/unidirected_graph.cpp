#include "unidirected_graph.hpp"

//implementazione del costruttore default
unidirected_graph::unidirected_graph() {};
//implementazione di costruttore copia
unidirected_graph::unidirected_graph(const unidirected_graph& other) {
    edges_ = other.edges_;
    adjacency_ = other.adjacency_;
    edge_to_number_ = other.edge_to_number_;
    number_to_edge_ = other.number_to_edge_;
}

//implementazione di  all_edges
std::set<unidirected_edge> unidirected_graph::all_edges() const {
    return edges_;
}

//implementazione di neighbours
std::set<int> unidirected_graph::neighbours(int node) const {
    // cerchiamo il nodo dentro il grafo
    auto it = adjacency_.find(node); // auto permette al codice di dedurre automaticamente il tipo della variabile dal contesto; .find() itera sulla map e auto deduce il tipo dell'iteratore
    // se non troviamo il nodo allora restituisce un set vuoto
    if (it == adjacency_.end()) { //adjancency non è un nodo ma è un iteratore speciale che indica "oltre l'ultimo elemento"; in questo modo restituisce un set vuoto
        return std::set<int>();
    }
    return it->second; // restiuiamo tutti i nodi vicini
}
//implementazione di all_nodes
std::set<int> unidirected_graph::all_nodes() const {
    std::set<int> nodes; // creaiamo il set di nodi
    // gli aggiungiamo tutti i nodi
    for (const auto& pair: adjacency_) {
        nodes.insert(pair.first);
    }
    return nodes;
}

//implementazione di add.edges()
void unidirected_graph::add_edge(const unidirected_edge& edge) {
    auto result = edges_.insert(edge);
    // .insert() restituisce un pair, in cui second vale true se è stato aggiuno o false se era già presente
    if (result.second == false) {
        return; //operazione completata
    } 
    //aggiorniamo la lista di adiacenza
    adjacency_[edge.from()].insert(edge.to()); //in entrambi i versi
    adjacency_[edge.to()].insert(edge.from());

    //numero l'arco aggiunto
    int number = static_cast<int>(edges_.size()) - 1; //numero degli archi già presenti -1 perché gli indici partono da 0
    edge_to_number_[edge] = number;
    number_to_edge_[number] = edge;


} 
//implementazione di edge_number
int unidirected_graph::edge_number(const unidirected_edge& edge) const {
    auto it = edge_to_number_.find(edge);

    // se non esiste restituiamo -1
    if (it == edge_to_number_.end()) {
        return -1; //valore sentinella, ovvero arco non trovato
    }

    //altrimenti
    return it->second;
}


//implementazione di edge_at
unidirected_edge unidirected_graph::edge_at(int number) const {
    auto it = number_to_edge_.find(number);

    //se non esiste restituiamo un arco fittizio
    if (it == number_to_edge_.end()) {
        return unidirected_edge(-1,-1);
    }

    return it->second;
}
//implementazione di operator-
unidirected_graph unidirected_graph::operator-(const unidirected_graph& other) const {

    unidirected_graph result; //grafo differenza

    // per ogni arco, controlliamo se è presente nell'other, altrimenti lo aggiungiamo al result
    for (const auto& edge : edges_) {
        if ((other.edges_.find(edge)) == other.edges_.end()) {
            result.add_edge(edge);
        }
    }
    return result;
}

