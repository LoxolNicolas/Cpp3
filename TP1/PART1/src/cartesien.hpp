#ifndef CARTESIEN_HPP
#define CARTESIEN_HPP

#include <cmath>

#include "point.hpp"
#include "polaire.hpp"

class Polaire;

class Cartesien : public Point
{
    private:
        double _x;
        double _y;
    
    public:
        Cartesien();
        Cartesien(const double& x, const double& y);
        Cartesien(const Polaire& p);

        inline const double& getX() const {return _x;}
        inline const double& getY() const {return _y;}

        void setX(const double& x);
        void setY(const double& y);

        virtual void afficher(std::ostream& flux) const override;

        void convertir(Polaire& p) const;
        void convertir(Cartesien& c) const;
};

#endif