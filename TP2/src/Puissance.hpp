#ifndef PUISSANCE_HPP
#define PUISSANCE_HPP

template<int N>
class Puissance
{
    public:
        static const double valeur(const double& nb)
        {
            return (Puissance<N-1>::valeur(nb) * nb);
        }
};

template<> 
class Puissance<0>
{
    public:
        static const double valeur(const double& nb)
        {
            return 1.0;
        }
};

#endif