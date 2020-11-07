#include "point.hpp"

std::ostream& operator<<(std::ostream& flux, const Point& p)
{
    p.afficher(flux);

    return flux;
}