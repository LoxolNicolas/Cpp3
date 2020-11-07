#include "vecteur.hpp"

//PAS DE VERIFICATION DES ALLOCATIONS (pas le but)

Vecteur::Vecteur() : _tab(nullptr), _taille(0), _taille_act(0)
{

}

Vecteur::Vecteur(unsigned int taille) : _tab(nullptr), _taille(taille), _taille_act(0)
{
    _tab = new int[taille];

    for(int i = 0; i < (int)_taille; i++) 
    {
        _tab[i] = 0;
    }
}

Vecteur::Vecteur(const Vecteur& vec) : _tab(nullptr), _taille(vec._taille), _taille_act(vec._taille_act)
{
    _tab = new int[_taille];

    for(int i = 0; i < (int)_taille; i++) 
    {
        _tab[i] = vec._tab[i];
    }
}

Vecteur::~Vecteur()
{
    if(_tab != nullptr)
    {
        delete[] _tab;
    }
}

void Vecteur::ajouter(const int& element)
{
    if(_taille_act == _taille)
    {
        std::cerr << "IMPOSSIBLE DE RAJOUER UN ELEMENT" << std::endl;
    }

    else
    {
        _tab[_taille_act++] = element;
    }
}

void Vecteur::supprimer()
{
    if(_taille_act == 0)
    {
        std::cerr << "IMPOSSIBLE DE SUPPRIMER L'ELEMENT" << std::endl;   
    }

    else
    {
        _tab[--_taille_act] = 0;
    }
}

Vecteur& Vecteur::operator=(const Vecteur& vec)
{
    if(this != &vec)
    {
        if(vec._taille != 0)
        {
            delete[] _tab; //detruit le contenu de vec avant la reafectation

            _taille = vec._taille;
            _taille_act = vec._taille_act;

            _tab = new int[_taille];

            for(int i = 0; i < (int)_taille; i++) 
            {
                _tab[i] = vec._tab[i];
            } 
        }
    }

    return *this;
}

int& Vecteur::operator[](std::size_t idx)
{
    if(idx > _taille)
    {
        throw std::out_of_range("Out of range");
    }

    return _tab[idx];
}

const int& Vecteur::operator[](std::size_t idx) const
{
    if(idx > _taille)
    {
        throw std::out_of_range("Out of range"); 
    }

    return _tab[idx];
}

Vecteur operator+(const Vecteur& v1, const Vecteur& v2)
{
    Vecteur vec(v1._taille + v2._taille);

    vec._taille_act = v1._taille_act + v2._taille_act;

    for(int i = 0; i < (int)v1._taille; i++) 
    {
        vec._tab[i] = v1._tab[i];
    }

    for(int j = 0; j < (int)v2._taille; j++) 
    {
        vec._tab[j + v1._taille] = v2._tab[j];
    }

    return vec;
}

Vecteur operator*(const Vecteur& v1, const int& scalaire)
{
    Vecteur vec(v1._taille);

    vec._taille_act = v1._taille_act;

    for(int i = 0; i < (int)vec._taille_act; i++) 
    {
        vec._tab[i] = v1._tab[i] * scalaire;
    }

    return vec;
}

std::ostream& operator<<(std::ostream& os, const Vecteur& vec)
{
    for(int i = 0; i < (int)vec._taille; i++) 
    {
        os << vec._tab[i] << " ";
    }

    os << std::endl;

    return os;
}

std::istream& operator>>(std::istream& is, Vecteur& vec)
{
    for(int i = 0; i < (int)vec._taille; i++) 
    {
        is >> vec._tab[i];
        vec._taille_act++;
    }

    return is;
}