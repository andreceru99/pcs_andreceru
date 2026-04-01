#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <concepts>
#include <iostream>
#include <numeric>

template<typename I>
requires std::integral<I>
class rational
{
    I num_;
    I den_;
    // aggiungo semplificazione
    void normalize()
    {
        if (den_ == 0) {
            if (num_ == 0) {
                return;     //NaN
            }
            if (num_ <0) {
                num_ = -1;
                return;     // Caso: -Inf
            }
            if (num_ >0) {
                num_ = 1;
                return;     // Caso: Inf
            }
        }

        if (num_ == 0) {
            den_ = 1;
            return;         // Caso: 0
        }

        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
        I g = std::gcd(num_ , den_); //https://en.cppreference.com/w/cpp/numeric/gcd.html trovo l'MCD
        // riduco ai minimi termini
        num_ /= g;
        den_ /= g; 
        /*
        Alternativa senza gcd, che non so se posso usare
        I MCD(a, b) {
            while(b!= 0) {
                I temp = b;
                b = a % b;
                a = temp
            }
            return a;
        }
        I g = MCD(num_ , den_);
        num_ /= g;
        den_ /= g; 
        */
    }


public:
    // costruttore default
    rational()
        : num_(0), den_(1) // definisco lo zero come 0/1
    {}
    // costruttore user-defined
    rational(const I& n, const I& d)
        : num_(n), den_(d) // ricavo numeratore e denominatore
    {
        normalize();
    }
    // definisco i getter
    I num() const
    {
        return num_;
    }
    I den() const
    {
        return den_;
    }

    /*Incremento*/
    //operatore +=
    rational& operator+=(const rational& other) {   // a+=b
        // se uno è NaN rimane NaN
        if (den_ == 0 && num_ == 0) {
        return *this;
        }
        if (other.den_ == 0 && other.num_ == 0) {
            num_ = 0; den_ = 0;
            return *this;
        }

        // se uno è Inf rimane Inf
        if (den_ == 0) {
            return *this;
        }
        if (other.den_ == 0) {
            num_ = other.num_;
            den_ = 0;
            return *this;
        }
        //modifico num_ e den_
        num_ = num_*other.den_+den_*other.num_;
        den_ = den_*other.den_;
        normalize(); //gestisco i vari casi
        return *this; // this è un pointer all'oggetto su cui sto lavorando
    }
    // operatore +
    // questo non restituisce un reference quindi non metto &
    // prende un const reference, restituisce per valore ed `e dichiarato const
    rational operator+(const rational& other) const{    // c = a+b --> c = (a+=b)
        rational c = *this; // metto a in temp
        c += other; // ci sommo b usando +=
        // qua non serve normalize() perché è già in +=
        return c; // restituisco un nuovo oggetto
    }
    /*Sottrazione*/
    rational& operator-=(const rational& other) {  

        // caso NaN
        if (den_ == 0 && num_ == 0) {
            return *this;
        }
        if (other.den_ == 0 && other.num_ == 0) {
            num_ = 0; den_ = 0;
            return *this;
        }

        // Inf - razionale
        if (den_ == 0) {
            return *this;
        }
        // razionale -Inf
        if (other.den_ == 0) {
            num_ = -other.num_;
            den_ = 0;
            return *this;
        }
        //Caso standard
        num_ = num_*other.den_ - den_*other.num_;
        den_ = den_*other.den_;
        normalize();
        return *this; 
    }
    rational operator-(const rational& other) const{    
        rational c = *this;
        c -= other; 
        return c; 
    }
    /*Moltiplicazione*/
    rational& operator*=(const rational& other) {   
        
        // NaN
        if (den_ == 0 && num_ == 0) {
            return *this;
        }
        if (other.den_ == 0 && other.num_ == 0) {
            num_ = 0; den_ = 0;
            return *this;
        }

        // caso in cui almeno uno dei due è infinito
        if (den_ == 0 || other.den_ == 0) {
            if (num_ == 0 || other.num_ == 0) {
                num_ = 0; den_ = 0; // NaN
            } else {
                if (((num_ > 0) && (other.num_ > 0)) || ((num_<0) && (other.num_) <0)) {
                    num_ = 1;
                }
                else {
                    num_ = -1;
                }
                den_ = 0;
            }
            return *this;
        }
        num_ = num_*other.num_;
        den_ = den_*other.den_;
        normalize();
        return *this; 
    }
    rational operator*(const rational& other) const{    
        rational c = *this;
        c *= other; 
        return c; 
    }
    /*Divisione*/
    rational& operator/=(const rational& other) {   
        
        // NaN
        if (den_ == 0 && num_ == 0) {
            return *this;
        }
        if (other.den_ == 0 && other.num_ == 0) {
        num_ = 0;
        den_ = 0;
        return *this;
    }

        // caso in cui divido per zero
        if(other.num_ == 0) {
            // potrei star dividendo un infinitoe
            den_ = 0;
            normalize();
            return *this;
        }

        // caso infinito diviso razionale
        if (den_ == 0) {
            return *this; //rimane infinito
        }
        // caso in cui divido per infinito
        if (other.den_ == 0) {
        num_ = 0;
        den_ = 1;  // ottengo 0
        return *this;
    }
        num_ = num_*other.den_;
        den_ = den_*other.num_;
        normalize();
        return *this; 
    }
    rational operator/(const rational& other) const{    
        rational c = *this;
        c /= other; 
        return c; 
    }
};
    

/* voglio poter scrivere 
std::cout << r << "\n"; 
per stampare il mio razionale
*/

// definisco l'operator <<
template<typename I>
requires std::integral<I>
std::ostream& operator<<(std::ostream& os, const rational<I>& r)
{
    //gestisco i vari casi con zero
    if (r.den() == 0) {
        if (r.num() == 0) os << "NaN";
        else if (r.num() > 0) os << "Inf";
        else os << "-Inf";
    } else {
        // output standard
        os << r.num() << "/" << r.den();
    }
    return os;
}



#endif