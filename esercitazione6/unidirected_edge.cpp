#include "unidirected_edge.hpp"

//implementazione del costruttore di default
unidirected_edge::unidirected_edge() {
    from_ = -1;
    to_ = -1;
}


// implementazione del costruttore
unidirected_edge::unidirected_edge(int a, int b) {
    if (a < b) {
        from_ = a;
        to_ = b;
    }
    else {
        from_ = b;
        to_ = a;
    }
}
// implementazione del metodo from()
int unidirected_edge::from() const {
    return from_;
}
// implementazione di to()
int unidirected_edge::to() const {
    return to_;
}
//implementazione dell'operator<
bool unidirected_edge::operator<(const unidirected_edge& other) const {
    if (from_ < other.from_) {
        return true;
    }
    if (from_ > other.from_) {
        return false;
    }
    if (to_ < other.to_) {
        return true;
    }
    if (to_ > other.to_) {
        return false;
    }
    return false; // negli altri casi
}
//implementazione dell'operator==
bool unidirected_edge::operator==(const unidirected_edge& other) const {
    return from_ == other.from_ && to_ == other.to_;    // in questo modo non c'è bisogno di fare l'elenco dei vari casi ma se entrambe le situazioni sono verificate restituisce True, altrimenti False
}
//implementazione dell'operator<<
std::ostream& operator<<(std::ostream&os, const unidirected_edge& e) {
    os << "(";
    os << e.from();
    os << ",";
    os << e.to();
    os << ")";

    return os;
}

