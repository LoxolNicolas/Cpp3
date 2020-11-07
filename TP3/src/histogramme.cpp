#include "histogramme.hpp"

Histogramme::Histogramme(double inf, double supp, double classesNb) : _inf(inf), _supp(supp), _classesNb(classesNb)
{
    for (int i = 0; i < _classesNb; i++)
    {
        _class_list.push_back(Classe(_inf + i * (_supp - _inf) / _classesNb, inf + (_supp - _inf) / _classesNb + i * (_supp - _inf) / _classesNb));
    }
}

const Histogramme::classes_t& Histogramme::getClasses() const
{
    return _class_list;
}

void Histogramme::ajouter(Echantillon e)
{
    for (size_t i = 0; i < _class_list.size(); i++)
    {
        for (size_t j = 0; j < e.getTaille(); j++)
        {
            if (e.getValeur(j).getNombre() < _class_list[i].getBorneSup() && e.getValeur(j).getNombre() >= _class_list[i].getBorneInf())
            {
                _class_list[i].ajouter();
            }
        }
    }
}