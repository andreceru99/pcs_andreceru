#include "rational.hpp"
#include <iostream>

int main()
{
    rational<int> r(3, 6);

    std::cout << r << "\n";

    return 0;
}