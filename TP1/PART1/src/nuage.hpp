#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>

#include "point.hpp"
#include "cartesien.hpp"

class Nuage
{
    public:
        using const_iterator = std::vector<Point*>::const_iterator;

    private:
        std::vector<Point*> vec;

    public:
        unsigned int size() const;

        void ajouter(Point& p);  

        const_iterator begin() const;
        const_iterator end() const;
};

Cartesien barycentre(const Nuage& n);

class BarycentreCartesien
{
    public:
        Cartesien operator()(const Nuage& n) 
        {
            return barycentre(n); //Rappel de barycentre()
        }
};

class BarycentrePolaire
{
    public:
        Polaire operator()(const Nuage& n) 
        {
            return Polaire(barycentre(n)); //Utilise operateur par copie car pas de formule mathematique facile
        }
};

#endif