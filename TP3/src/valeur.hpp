#ifndef VALEUR_HPP
#define VALEUR_HPP

class Valeur
{
    private:
        double _val;

    public:
        Valeur();
        Valeur(const double& val);
        
        const double& getNombre() const;
        void setNombre(const double& nb);
};

#endif