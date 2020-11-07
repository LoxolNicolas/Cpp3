#include "valeur.hpp"

Valeur::Valeur() : _val(0.0)
{

}

Valeur::Valeur(const double& val) : _val(val)
{

}

const double& Valeur::getNombre() const
{
    return _val;
}

void Valeur::setNombre(const double& nb)
{
    _val = nb;
}