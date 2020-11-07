#include "polaire.hpp"

Polaire::Polaire() : _angle(0.0), _distance(0.0)
{

}

Polaire::Polaire(const double& angle, const double& distance) : _angle(angle), _distance(distance)
{

}

Polaire::Polaire(const Cartesien& c)
{
    c.convertir(*this);
}

void Polaire::setAngle(const double& angle)
{
    _angle = angle;
}

void Polaire::setDistance(const double& distance)
{
    _distance = distance;
}

void Polaire::afficher(std::ostream& flux) const
{
    flux << "(a=" << _angle << ";d=" << _distance << ")";
}

void Polaire::convertir(Cartesien& c) const
{
    c.setX(_distance * std::cos(_angle * (M_PI / 180)));
    c.setY(_distance * std::sin(_angle * (M_PI / 180)));
}

void Polaire::convertir(Polaire& p) const
{
    p.setAngle(_angle);
    p.setDistance(_distance);
}