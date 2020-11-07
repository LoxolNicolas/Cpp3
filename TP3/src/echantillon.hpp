#ifndef ECHANTILLON_HPP
#define ECHANTILLON_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include "valeur.hpp"

class Echantillon
{
    private:
        std::vector<Valeur> _val_list;

    public:
        Echantillon();

        unsigned int getTaille() const;

        void ajouter(const Valeur& v);
        Valeur getMinimum() const;
        Valeur getMaximum() const;
        Valeur getValeur(unsigned int id) const;
};

#endif