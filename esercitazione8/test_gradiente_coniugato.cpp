#include <iostream>
#include <Eigen/Dense>

#include "gradiente_coniugato.hpp"

int main() {
    //int n = 1000;
    //int n = 100;
    int n = 15;
    // matrice simmetrica definita positiva
    Eigen::MatrixXd B = Eigen::MatrixXd::Random(n,n);
    Eigen::MatrixXd A = B.transpose() *B;


    // soluzione esatta

    Eigen::VectorXd x_esatta = Eigen::VectorXd::Ones(n);


    // costruzione di b
    Eigen::VectorXd b = A*x_esatta;

    // soluzione iniziale nulla 
    Eigen::VectorXd x0 = Eigen::VectorXd::Zero(n);

    // tolleranza
    double tol = 1e-10;

    // numero massimo di iterazione
    int max_iter = 100;

    Eigen::VectorXd x = gradiente_coniugato(A, b, x0, tol, max_iter);

    std::cout << "Soluzione esatta: \n" << x_esatta <<"\n";
    std::cout << "Soluzione numerica: \n" << x << "\n";

    std::cout << "Errore relativo:\n" << (x-x_esatta).norm()/ x_esatta.norm()<<"\n";




}