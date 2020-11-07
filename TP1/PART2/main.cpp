#include "vecteur.hpp"

int main(int, char**)
{
    Vecteur v1(5);
    Vecteur v2(3);

    v1.ajouter(1);
    v1.ajouter(2);
    v1.ajouter(3);
    
    Vecteur v = v1 * 3;

    std::cout << v;
    std::cout << v.get_taille() << std::endl;
    std::cout << v.get_taille_act() << std::endl;

    return 0;
}