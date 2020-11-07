#include "nuage.hpp"

unsigned int Nuage::size() const
{
    return vec.size();
}
        
void Nuage::ajouter(Point& p)
{
    vec.push_back(&p);
}

Nuage::const_iterator Nuage::begin() const
{
    return vec.begin();
}

Nuage::const_iterator Nuage::end() const
{
    return vec.end();
}

Cartesien barycentre(const Nuage& n)
{
    Cartesien tmp;

    double x = 0.0, y = 0.0;

    for(Nuage::const_iterator it = n.begin(); it != n.end(); it++) 
    {
        (*it)->convertir(tmp);

        x+=tmp.getX();
        y+=tmp.getY();
    }

    return ((n.size() == 0) ? Cartesien(0.0, 0.0) : Cartesien(x / n.size() , y / n.size()));
}
