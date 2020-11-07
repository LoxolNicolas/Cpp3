#ifndef EXPONENTIELLE_HPP
#define EXPONENTIELLE_HPP

#include "Puissance.hpp"
#include "Factorielle.hpp"

template<int N>
class Exponentielle
{
    public:
        static const double valeur(const double& nb)
        {
            return (Puissance<N>::valeur(nb)) / (Factorielle<N>::valeur) + Exponentielle<N - 1>::valeur(nb);
        }
};

template<>
class Exponentielle<0>
{
    public:
        static const double valeur(const double& nb)
        {
            return (Puissance<0>::valeur(nb) / Factorielle<0>::valeur);
        }
};

#endif