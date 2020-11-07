#ifndef HISTOGRAMME_HPP
#define HISTOGRAMME_HPP

#include <iostream>
#include <vector>
#include "classe.hpp"
#include "echantillon.hpp"


class Histogramme
{
    public :
        using classes_t = std::vector<Classe>;
        Histogramme(double inf, double supp, double quantite);
        const classes_t& getClasses() const;
        void ajouter(Echantillon e);
    
    private :
        classes_t _class_list;
        double _inf;
        double _supp;
        double _classesNb;
};

#endif