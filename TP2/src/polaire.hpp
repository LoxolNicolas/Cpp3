#ifndef POLAIRE_HPP
#define POLAIRE_HPP

#include "point.hpp"
#include "cartesien.hpp"

class Cartesien;

class Polaire : public Point
{
    private:
        double _angle;
        double _distance;
    
    public:
        Polaire();
        Polaire(const double& angle, const double& distance);
        Polaire(const Cartesien& c);

        inline const double& getAngle() const {return _angle;}
        inline const double& getDistance() const {return _distance;}

        void setAngle(const double& angle);
        void setDistance(const double& distance);

        virtual void afficher(std::ostream& flux) const override;

        void convertir(Cartesien& c) const;
        void convertir(Polaire& p) const;
};

#endif