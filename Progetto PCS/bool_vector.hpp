#ifndef BOOL_VECTOR_HPP
#define BOOL_VECTOR_HPP

#include <vector>
#include <iostream>
#include <stdexcept>

class bool_vector
{
private:

    std::vector<int> data_;

public:

    // Costruttore vuoto
    bool_vector() = default;

    // Costruttore: vettore booleano di lunghezza n inizializzato a 0
    explicit bool_vector(int n)
        : data_(n, 0)
    {
        if (n < 0)
        {
            throw std::invalid_argument("La dimensione del vettore deve essere non negativa");
        }
    }

    // Costruttore da std::vector<int>
    explicit bool_vector(const std::vector<int>& data)
        : data_(data)
    {
        for (int x : data_)
        {
            if (x != 0 && x != 1)
            {
                throw std::invalid_argument("bool_vector puo contenere solo 0 o 1");
            }
        }
    }

    // Dimensione del vettore
    int size() const
    {
        return static_cast<int>(data_.size());
    }

    // Lettura elemento in posizione i
    int operator[](int i) const
    {
        return data_[i];
    }

    // Modifica elemento in posizione i
    int& operator[](int i)
    {
        return data_[i];
    }

    // Imposta l'elemento i a 0 oppure 1
    void set(int i, int x)
    {
        if (x != 0 && x != 1)
        {
            throw std::invalid_argument("Il vettore booleano puo contenere solo 0 o 1");
        }

        data_[i] = x;
    }

    // Cambia 0 in 1 oppure 1 in 0
    void flip(int i)
    {
        data_[i] = 1 - data_[i];
    }

    // Prodotto scalare modulo 2
    int prod_scal_mod2(const bool_vector& other) const
    {
        if (size() != other.size())
        {
            throw std::invalid_argument("I vettori booleani hanno dimensioni diverse");
        }

        int result = 0;

        for (int i = 0; i < size(); i++)
        {
            result += data_[i] * other.data_[i];
        }

        return result % 2;
    }

    // Differenza simmetrica tramite XOR: this = this XOR other
    void xor_with(const bool_vector& other)
    {
        if (size() != other.size())
        {
            throw std::invalid_argument("I vettori hanno dimensioni incompatibili per XOR");
        }

        for (int i = 0; i < size(); i++)
        {
            data_[i] = data_[i] ^ other.data_[i];
        }
    }

    // Versione comoda: v += w significa v = v XOR w
    bool_vector& operator+=(const bool_vector& other)
    {
        xor_with(other);
        return *this;
    }

    // Controlla se il vettore è tutto nullo
    bool empty() const
    {
        for (int x : data_)
        {
            if (x != 0)
            {
                return false;
            }
        }

        return true;
    }

    // Accesso al vettore interno
    const std::vector<int>& data() const
    {
        return data_;
    }

    // Stampa
    friend std::ostream& operator<<(std::ostream& os, const bool_vector& v)
    {
        os << "(";

        for (int i = 0; i < v.size(); i++)
        {
            os << v[i];

            if (i + 1 < v.size())
            {
                os << ", ";
            }
        }

        os << ")";

        return os;
    }
};

#endif