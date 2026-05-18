#ifndef LIFO_HPP
#define LIFO_HPP

#include <stack>

template<typename T>
class lifo {
    private:
    std::stack<T> s_;

    public:
    // costruttore default
    lifo() = default;
    
    // put(x)
    void put(const T& value) {
        s_.push(value); //inserisce in cima alla coda
    }
    
    // get()
    T get() {
        T value = s_.top(); // prima legge l'ultimo elemento inserito 
        s_.pop(); // poi lo rimuove
        return value;
    }
    
    // empty()
    bool empty() const {
        return s_.empty();
    }

};



#endif