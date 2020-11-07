#include "nuage.hpp"

template<typename T>
unsigned int Nuage<T>::size() const
{
    return vec.size();
}

template<typename T>
void Nuage<T>::ajouter(const T& element)
{
    vec.push_back(element);
}

template<typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const
{
    return vec.begin();
}

template<typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const
{
    return vec.end();
}

template<typename T>
T barycentre_v1(const Nuage<T>& n)
{
    Cartesien c;

    double x = 0.0, y = 0.0;

    for(typename Nuage<T>::const_iterator it = n.begin(); it != n.end(); it++)
    {
        it->convertir(c); //appel methode virtuelle
        //c = (Cartesien)(*it); //Cast
        x += c.getX();
        y += c.getY();
    }

    return (n.size() > 0) ? T(Cartesien(x / n.size(), y / n.size())) : T(Cartesien(0.0, 0.0));
}

template<>
Polaire barycentre_v1<Polaire>(const Nuage<Polaire>& n)
{
    double angle = 0, theta = 0;

    for(typename Nuage<Polaire>::const_iterator it = n.begin(); it != n.end(); it++)
    {
        angle += it->getAngle();
        theta += it->getDistance();
    }

    return (n.size() > 0) ? Polaire(angle / n.size(), theta / n.size()) : Polaire(0.0, 0.0);
}

template<typename Container> 
typename Container::value_type barycentre_v2(const Container& c) 
{
    Cartesien cart;

    double x = 0.0, y = 0.0;

    for(typename Container::const_iterator it = c.begin(); it != c.end(); it++) 
    {
        it->convertir(cart);

        x += cart.getX();
        y += cart.getY();
    }

    return (c.size() == 0 ? typename Container::value_type() : typename Container::value_type(Cartesien(x / c.size(), y / c.size())));
}

Cartesien barycentre_v2(const Nuage<Cartesien>& n)
{
    Cartesien c;

    double x = 0, y = 0;

    for(typename Nuage<Cartesien>::const_iterator it = n.begin(); it != n.end(); it++)
    {
        it->convertir(c);
        x += c.getX();
        y += c.getY();
    }

    return (n.size() > 0) ? Cartesien(x / n.size(), y / n.size()) : Cartesien(0.0, 0.0);
}

/*
Cartesien barycentre_v2(const std::vector<Cartesien>& vec_c)
{
    double x = 0.0, y = 0.0;

    for(int i = 0; i < (int)vec_c.size(); i++) 
    {
        x += vec_c[i].getX();
        y += vec_c[i].getY();
    }

    return (vec_c.size() > 0) ? Cartesien(x / vec_c.size(), y / vec_c.size()) : Cartesien(0.0, 0.0);
}

Polaire barycentre_v2(const std::vector<Polaire>& vec_p)
{
    Polaire p;

    double x = 0, y = 0;

    for(int i = 0; i < (int)vec_p.size(); i++)
    {
        vec_p[i].convertir(p);
        x+= p.getAngle();
        y+= p.getDistance();
    }

    return (vec_p.size() > 0) ? Polaire(x / vec_p.size(), y / vec_p.size()) : Polaire(0.0, 0.0);
}
*/