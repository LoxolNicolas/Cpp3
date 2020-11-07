#include "echantillon.hpp"

Echantillon::Echantillon()
{

}

unsigned int Echantillon::getTaille() const
{
    return _val_list.size();
} 

void Echantillon::ajouter(const Valeur& v)
{
    _val_list.push_back(v);
}

Valeur Echantillon::getMinimum()
{
    if(_val_list.empty())
    {
        throw std::domain_error("LISTE VIDE");
    }

    else
    {
        return *(std::min_element(_val_list.begin(), _val_list.end(), [](Valeur a, Valeur b) {return (a.getNombre() < b.getNombre());}));
    }   
}

Valeur Echantillon::getMaximum()
{
     if (_val_list.empty())
    {
        throw std::domain_error("ERREUR");
    }  
    else
    {
        return *(std::max_element(_val_list.begin(), _val_list.end(), [](Valeur a, Valeur b) {return (a.getNombre() < b.getNombre());}));
    }
}

Valeur Echantillon::getValeur(unsigned int id)
{
    if (id >= _val_list.size() || id < 0)
    {
        throw std::out_of_range("ERREURRRRRR :)");
    }
    else
    {
        return _val_list[id];
    }
}
