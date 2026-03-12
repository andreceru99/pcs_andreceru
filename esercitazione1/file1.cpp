#include <iostream>
#include <fstream>
#include <string>


int main(int argc, const char *argv[])
    {
    // se non vengono inserite almeno due parametri il programma restituisce errore
    if (argc<2) {
        std::cerr << "Errore: devi specificare il nome del file\n";
        return 1;
        }
    std::string filename = argv[1]; //metto il nome del file dentro filename
    std::ifstream ifs(filename); // apriamo il file dentro ifs

    // verifichiamo che il file si è aperto correttamente
    if (!ifs.is_open()) {
        std::cerr << "Errore: il file non si è aperto correttamente\n";
        return 1;
    }
    std::string citta; // creiamo la variabile stringa per il nome della città
    double t0, t6, t12, t18; // creiamo 4 variabili per le temperature decimali



    while (!ifs.eof()) {
        ifs >> citta >> t0 >> t6 >> t12 >> t18;
        // per ogni riga del file prendiamo il nome della città e le relative temperature
        double media = (t0 + t6 + t12 + t18)/4.0; // definisco la variabile media
        std::cout << citta <<" "<< media <<"\n"; // stampo
    } 
return 0;
}