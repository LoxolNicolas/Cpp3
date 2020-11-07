#include "classe.hpp"

Classe::Classe(double a, double b) : _borneInf(a), _borneSup(b), _quantite(0)
{

}

double Classe::getBorneInf() const
{
    return _borneInf;
}

double Classe::getBorneSup() const
{
    return _borneSup;
}

double Classe::getQuantite() const
{
    return _quantite;
}

void Classe::setBorneInf(double inf)
{
    _borneInf = inf;
}

void Classe::setBorneSup(double sup)
{
    _borneSup = sup;
}

void Classe::setQuantite(double quantite)
{
    _quantite = quantite;
}

void Classe::ajouter()
{
    _quantite++;
}