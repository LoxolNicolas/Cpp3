#include "cartesien.hpp"

Cartesien::Cartesien() : _x(0.0), _y(0.0)
{

}

Cartesien::Cartesien(const double& x, const double& y) : _x(x), _y(y)
{

}

Cartesien::Cartesien(const Polaire& p)
{
    p.convertir(*this);
}

void Cartesien::setX(const double& x)
{
    _x = x;
}

void Cartesien::setY(const double& y)
{
    _y = y;
}

void Cartesien::afficher(std::ostream& flux) const
{
    flux << "(x=" << _x << ";y=" << _y << ")";
}

void Cartesien::convertir(Polaire& p) const
{
    p.setDistance(std::sqrt(std::pow(_x, 2) + std::pow(_y, 2)));
    p.setAngle(std::atan(_y / _x) * (180.0 / M_PI));
}

void Cartesien::convertir(Cartesien& c) const
{
    c.setX(_x);
    c.setY(_y);
}