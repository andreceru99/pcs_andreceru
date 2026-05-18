#include <iostream>

#include "fifo.hpp"
#include "lifo.hpp"

int main() {
    fifo<int> q;

    q.put(1);
    q.put(2);
    q.put(3);

    std::cout <<"FIFO:\n";
    while (!q.empty()) {
        std::cout << q.get() << "\n";
    }

    lifo<int> s;

    s.put(1);
    s.put(2);
    s.put(3);

    std::cout <<"LIFO:\n";
    while(!s.empty()) {
        std::cout << s.get() << "\n";
    }


    return 0;
}



/*
output test
FIFO:
1
2
3
LIFO:
3
2
1
*/