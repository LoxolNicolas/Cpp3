#ifndef SINUS_HPP
#define SINUS_HPP

#include "Puissance.hpp"
#include "Factorielle.hpp"

template<int N>
class Sinus
{
    public:
        static const double valeur(const double& nb)
        {
            return (Puissance<N>::valeur(-1)) * (Puissance<(2*N) + 1>::valeur(nb) / Factorielle<(2*N) + 1>::valeur) + Sinus<N-1>::valeur(nb);
        }
};

template<>
class Sinus<0>
{
    public:
        static const double valeur(const double& nb)
        {
            return (Puissance<0>::valeur(-1)) * (Puissance<1>::valeur(nb) / Factorielle<1>::valeur);
        }
};

#endif