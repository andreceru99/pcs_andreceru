#ifndef MATRICE_B_HPP
#define MATRICE_B_HPP

#include <Eigen/Dense>
#include <vector>
#include <map>
#include <stdexcept>

#include "unidirected_edge.hpp"


// funzione per verificare il segno del valore della resistenza
inline int segno_lato(int from, int to)
{
    if(from == to) {
        throw std::runtime_error("Errore: from == to");
    }

    if(from < to) {
        return +1;
    }

    return -1;
}


template<typename ResistenzeContainer>
Eigen::MatrixXd costruzione_matrice_B(
    const std::vector<std::vector<int>>& cicli,
    const ResistenzeContainer& resistenza_valore
)
{
    /*questa struttura ci serve per evitare un terzo ciclo for sulle resistenza nella costruzione della matrice*/

    // numero di righe di B
    const int numero_resistenze = static_cast<int>(resistenza_valore.size());

    // numero di colonne
    const int numero_cicli = static_cast<int>(cicli.size());

    // inizializzazione della matrice B
    Eigen::MatrixXd B = Eigen::MatrixXd::Zero(numero_resistenze, numero_cicli);

    // struttura per richiamare gli archi con le resistenze
    std::map<unidirected_edge<int>, int> indice_riga_arco;

    
    // ciclo per associare ogni resistenza al rispettivo arco
    int riga = 0; 
    for(const auto& coppia : resistenza_valore)
    {
        unidirected_edge<int> arco_resistenza(
            coppia.second.from,
            coppia.second.to
        );

        indice_riga_arco[arco_resistenza] = riga;

        ++riga;
    }

    // ciclo su ogni ciclo trovato
    for(int j = 0; j < numero_cicli; ++j)
    {
        // j-esimo ciclo che consideriamo
        const std::vector<int>& ciclo = cicli[j];

        // ciclo su ogni arco del ciclo
        for(int k = 0; k < ciclo.size(); ++k)
        {
            int from = ciclo[k];
            int to;

            // condizione per la verifica dell'arco di chiusura della maglia
            if (k+1 == ciclo.size()) {
                to = ciclo[0];
            }
            else {
                to = ciclo[(k + 1)]; 
            }

            unidirected_edge<int> arco_lato(from, to);

            auto it = indice_riga_arco.find(arco_lato);

            // controlliamo che l'indice sia quello di una resistenza, altrimenti è quello di un generatore e non ci interessa inserire i generatori dentro B
            if(it == indice_riga_arco.end())
            {
                continue;
            }

            // elemento a cui punta it, prendo il secondo valore della coppia
            int i = (*it).second;

            B(i, j) = segno_lato(from, to); // aggiorno dentro la matrice
        }
    }
    return B;
}


#endif
