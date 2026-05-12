#ifndef UNIDIRECTED_EDGE_HPP
#define UNIDIRECTED_EDGE_HPP

#include <iostream>

// classe che rappresenta un singolo arco del grafo
class unidirected_edge {

    private:
    //variabili
    int from_;
    int to_;

    public:
    unidirected_edge();
    unidirected_edge(int a, int b);

    int from() const;
    int to() const;

    bool operator<(const unidirected_edge& other) const;
    bool operator==(const unidirected_edge& other) const;

};

std::ostream& operator<<(
    std::ostream& os, 
    const unidirected_edge& e
);

#endif