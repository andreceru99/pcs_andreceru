#ifndef GRADIENTE_CONIUGATO_HPP
#define GRADIENTE_CONIUGATO_HPP

#include <Eigen/Dense>
#include <iostream>

Eigen::VectorXd gradiente_coniugato(
    const Eigen::MatrixXd& A, // matrice del sistema -> usiamo una matrice dinamica di double
    const Eigen::VectorXd& b,// termine noto -> usiamo una vettore dinamico di double
    const Eigen::VectorXd& x0,// soluzione inziale
    double tol, // tollerenza
    int max_iter

) {
    Eigen::VectorXd x = x0; // vettore soluzione corrente
    Eigen::VectorXd r = b - A*x; // vettore residuo corrente
    Eigen::VectorXd p = r; 
    int k = 0;
    while (r.norm()  >= tol && k < max_iter) {

        double alpha = ((p.transpose() * r ) / (p.transpose()*A*p)).value(); // definisco alpha
        x = x + alpha * p; // aggiorno la soluzione
        Eigen::VectorXd r_new = b - A*x; // residuo nuovo 
        double beta = ((p.transpose()*A*r_new) / (p.transpose()*A*p)).value(); // definisco beta
        p = r_new - beta * p; // aggiorno il passo
        r = r_new; // aggiorno il residuo

        k ++; 


    }  
    if(k == max_iter)
    {
        std::cout << "Numero massimo di iterazioni raggiunto\n";
    }
    else
    {
        std::cout << "Convergenza raggiunta in "
                << k
                << " iterazioni\n";
}    return x;
}



#endif