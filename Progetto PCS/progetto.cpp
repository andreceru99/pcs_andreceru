
#include <fstream>
#include <iostream>
#include <vector>
#include <Eigen/Dense>
#include <set>
#include <list>
#include <string>
#include <map>
#include <string_view>

#include "unidirected_graph.hpp"
#include "unidirected_edge.hpp"
#include "to_dot.hpp"
#include "lifo.hpp"
#include "graph_visit.hpp"
#include "path.hpp"
#include "gradiente_coniugato.hpp"
#include "bool_vector.hpp"
#include "depina.hpp"
#include "matrice_B.hpp"
#include "vettore_V.hpp"

// #include "matrice_B.hpp"

// struttura dati per interpretare l'input
struct componente {
    double valore;
    int from;
    int to;
};

int main(int argc, char* argv[]) {
    unidirected_graph<int> G;
    
    if (argc<3) {
        std::cout << "Errore uso corretto:\n";
        std::cout << "./progetto nome_del_file metodo\n";
        std::cout << "ove metodo può essere depina o dfs\n";
        return 1;
    }

    std::string metodo = argv[2];

    std::ifstream ifs(argv[1]);
    if (ifs.is_open()) {
        // variabili per il ciclo
        std::string tipo;
        double valore;
        int from;
        int to;

        std::map<std::string, componente> resistenza_valore;
        std::map<std::string, componente> generatore_valore;
        
        // riscrittura input come struttura dati
        while(ifs >> tipo >> valore >> from >> to) {
            componente c{valore, from, to};

            if(tipo[0]=='R'){
                resistenza_valore[tipo] = c;
            }else{
                generatore_valore[tipo] = c;
            }
            G.add_edge(unidirected_edge<int>(from, to));
        }

        lifo<int> s; 
        // albero di supporto con il dfs
        unidirected_graph<int> dfsT = graph_visit(G, 1, s); 
        // albero differenza G -T
        unidirected_graph<int> diff = G-dfsT;


        to_dot(G, "grafo.dot");
        to_dot(dfsT, "dfsT.dot");
        to_dot(diff, "diff.dot");
        
        std::vector<std::vector<int>> cicli;


        /* scegliamo che metodo usare */

        /*DFS*/
        if (metodo == "dfs") {
            std::cout << "Metodo scelto: DFS\n";

            //inserisco il metodo

            for(const auto& edge: diff.all_edges()){
                std::vector<int> path;
                std::map<int,bool> visited;
                findpath(dfsT,edge.from(),edge.to(), visited, path);
                cicli.push_back(path);
            }

            //stampo i cicli ottenuti nel primo metodo
            for(const auto& n:cicli){
                std::cout<<"Ciclo: [";
                for(const auto& elem:n){
                    std::cout<<" "<<elem;
                }
                std::cout<<"] \n";
            }
        }

        /*DEPINA*/
        else if (metodo == "depina") {
            std::cout << "Metodo scelto: Depina\n";

            // inserisco il metodo

            std::vector<bool_vector> S = initialize_S_vectors(G, diff);
            std::vector<depina_cycle> base = de_pina(G, S);

            // stampa:
            for (int i = 0; i < static_cast<int>(base.size()); i++) {
            std::cout << "Ciclo: [ ";

                for (int v : base[i].vertices) {
                    std::cout << v << " ";
                }

            std::cout << "]\n";
            }

            // aggiorno cicli
            for (int i = 0; i < base.size() ; i++) {
                cicli.push_back(base[i].vertices);
            }
        }
        // metodo scritto in maniera errata
        else {
            std::cout <<"Metodo non corretto";
            return 1;
            
        }

        // inizio a costriure le matrici per eseguire i calcoli
        
        /*Matrice B*/      
        //abbiamo modificato come costruiamo la matrice B per migliorarla, sia a livello di costo che come funzionamento
        
        Eigen::MatrixXd B = costruzione_matrice_B(cicli, resistenza_valore);
        

        std::cout<<"Matrice B "<<'\n';
        std::cout << B << '\n';
        
        
        /*Matrice R*/
        
        int N = resistenza_valore.size(); //numero resistenze
        Eigen::MatrixXd R = Eigen::MatrixXd::Zero(N,N);
        int t=0;
        for (const auto & coppia : resistenza_valore) {
            double resistenza = coppia.second.valore;
            R(t,t) = resistenza;
            t++;
        }
        std::cout<<"Matrice R "<<'\n'<< R << std::endl;

        
        /*Vettore V*/
        // anche qua abbiamo modificato la costruizione del vettore per migliorarla 

        Eigen::VectorXd V = costruzione_vettore_V(cicli, generatore_valore);

        std::cout<<"Vettore V: \n";
        std::cout<<V<<"\n";
        

        /*Calcoli*/

        Eigen::MatrixXd A = B.transpose()*R*B;

        Eigen::VectorXd x0 = Eigen::VectorXd::Zero(cicli.size());
        const double r_tol = 1.0e-12;
        Eigen::VectorXd x = gradiente_coniugato(A,V,x0,r_tol,1000);
        
        Eigen::VectorXd i = B * x;

        Eigen::VectorXd Tensioni=R*i;

        //stampa
        int w=0;
        for(const auto& key:resistenza_valore){
            std::cout<<key.first<<": ";
            std::cout<<"V= "<<Tensioni[w]<<" volts, ";
            std::cout<<"I= "<<i[w]<<" amps.\n";
            w++;
        }

    } else {
        std::cout << "Errore nell'apertura del file";
    }

    return 0;
}
