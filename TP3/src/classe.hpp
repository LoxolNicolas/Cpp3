#ifndef CLASSE_HPP
#define CLASSE_HPP

class Classe
{
    public :
        Classe(double a, double b);
        double getBorneInf() const;
        double getBorneSup() const;
        double getQuantite() const;

        void setBorneInf(double);
        void setBorneSup(double);
        void setQuantite(double);

        void ajouter();

    
    private :
        double _borneInf;
        double _borneSup;
        unsigned int _quantite;
};

#endif