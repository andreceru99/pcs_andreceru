#include <iostream>
int main(int argc, const char *argv[]) {
    // in argc viene inserito il numero di parametri passati
    // in argv[i] viene inserito il parametro i, dove i =0,1, ...
    std::cout << "Numero di parametri: " << argc << "\n";
    for (int i = 0; i < argc; i++) {
        std::cout << "Parametro " << i << " = " << argv[i] << "\n";
    }
    return 0;

}