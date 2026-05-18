#ifndef FIFO_HPP
#define FIFO_HPP

#include <queue>


template<typename T>
class fifo {
    private: 
    std::queue<T> q_;

    public:

    // costruttore default
    fifo() = default;
    
    // put(x)
    void put(const T& value) {
        q_.push(value); //inserisce in fondo alla coda
    }
    
    // get()
    T get() {
        T value = q_.front(); // prima legge l'elemento in cima alla coda 
        q_.pop(); // poi lo rimuove
        return value;
    }
    
    // empty()
    bool empty() const {
        return q_.empty();
    }



};


#endif