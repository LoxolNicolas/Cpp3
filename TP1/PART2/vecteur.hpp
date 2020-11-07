#ifndef VECTEUR_HPP
#define VECTEUR_HPP

#include<iostream>
#include<vector>

class Vecteur
{
    private:
        int* _tab;
        unsigned int _taille;
        unsigned int _taille_act;

    public:
        Vecteur();
        Vecteur(unsigned int taille);
        Vecteur(const Vecteur& vec);
        ~Vecteur();

        inline const unsigned int& get_taille() {return _taille;}
        inline const unsigned int& get_taille_act() {return _taille_act;}

        void ajouter(const int& element);
        void supprimer();

        Vecteur& operator=(const Vecteur& vec);
        int& operator[](std::size_t idx);
        const int& operator[](std::size_t idx) const;

        friend Vecteur operator+(const Vecteur& v1, const Vecteur& v2);
        friend Vecteur operator*(const Vecteur& v1, const int& scalaire);

        friend std::ostream& operator<<(std::ostream& os, const Vecteur& vec);
        friend std::istream& operator>>(std::istream& is, Vecteur& vec);
};

#endif