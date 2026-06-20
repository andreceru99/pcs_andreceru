#ifndef VETTORE_V_HPP
#define VETTORE_V_HPP

#include <Eigen/Dense>

#include <vector>
#include <map>
#include <stdexcept>

#include "unidirected_edge.hpp"

// anche qua utilizziamo una struttura dati
struct dati_generatore
{
    int from;
    int to;
    double valore;
};


// funzione per calcolare il contributo del generatore
inline double contributo_generatore(
    int from_ciclo,
    int to_ciclo,
    const dati_generatore& generatore
)
{
    if(from_ciclo == to_ciclo)
    {
        throw std::runtime_error("Errore: from_ciclo == to_ciclo");
    }

    /*
    Se percorro il generatore nello stesso verso scritto nella netlist,
    cioè generatore.from -> generatore.to, il contributo è negativo.

    Se lo percorro nel verso opposto, il contributo è positivo.
    */

    if(from_ciclo == generatore.from && to_ciclo == generatore.to)
    {
        return -generatore.valore;
    }
    else
    {
        return +generatore.valore;
    }
}


template<typename GeneratoriContainer>
Eigen::VectorXd costruzione_vettore_V(
    const std::vector<std::vector<int>>& cicli,
    const GeneratoriContainer& generatore_valore
)
{
    // numero di componenti del vettore V
    int numero_cicli = cicli.size();

    // inizializzazione del vettore V
    Eigen::VectorXd V = Eigen::VectorXd::Zero(numero_cicli);

    /*
    Questa struttura ci serve per evitare un terzo ciclo for
    sui generatori durante la costruzione del vettore V.
    */
    std::map<unidirected_edge<int>, dati_generatore> generatore_arco;

    // ciclo per associare ogni generatore al rispettivo arco
    for(const auto& coppia : generatore_valore)
    {
        dati_generatore generatore;

        generatore.from = coppia.second.from;
        generatore.to = coppia.second.to;
        generatore.valore = coppia.second.valore;

        unidirected_edge<int> arco_generatore(
            generatore.from,
            generatore.to
        );

        generatore_arco[arco_generatore] = generatore;
    }

    // ciclo su ogni ciclo trovato
    for(int j = 0; j < numero_cicli; ++j)
    {
        // j-esimo ciclo che consideriamo
        const std::vector<int>& ciclo = cicli[j];

        double somma = 0;

        // ciclo su ogni lato del ciclo
        for(int k = 0; k < ciclo.size(); ++k)
        {
            int from = ciclo[k];
            int to;

            // condizione per la verifica dell'arco di chiusura della maglia
            if(k + 1 == ciclo.size())
            {
                to = ciclo[0];
            }
            else
            {
                to = ciclo[k + 1];
            }

            unidirected_edge<int> arco_lato(from, to);

            auto it = generatore_arco.find(arco_lato);

            /*
            Se il lato del ciclo non è presente tra i generatori,
            allora è una resistenza e non contribuisce al vettore V.
            */
            if(it == generatore_arco.end())
            {
                continue;
            }

            dati_generatore generatore = (*it).second;

            somma += contributo_generatore(from, to, generatore);
        }

        V[j] = somma;
    }

    return V;
}

#endif