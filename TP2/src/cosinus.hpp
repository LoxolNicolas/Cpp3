#ifndef COSINUS_HPP
#define COSINUS_HPP

template<int N>
class Cosinus
{
    public:
        static const double valeur(const double& nb)
        {
            return (Puissance<N>::valeur(-1)) * (Puissance<2*N>::valeur(nb) / Factorielle<2*N>::valeur) + Cosinus<N-1>::valeur(nb);
        }
};

template<>
class Cosinus<0>
{
    public:
        static const double valeur(const double& nb)
        {
            return (Puissance<0>::valeur(-1)) * (Puissance<0>::valeur(nb) / Factorielle<0>::valeur);
        }
};


#endif