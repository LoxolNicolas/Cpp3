#ifndef NUAGE_HPP
#define NUAGE_HPP

#include <vector>

#include "cartesien.hpp"

template<typename T>
class Nuage
{
    public:
        using const_iterator = typename std::vector<T>::const_iterator;

    private:
        std::vector<T> vec;

    public:
        unsigned int size() const;
        void ajouter(const T& element);

        const_iterator begin() const;
        const_iterator end() const;
};

#include "nuage.hxx"

template<typename T>
T barycentre_v1(const Nuage<T>& n);

Cartesien barycentre_v2(const Nuage<Cartesien>& n);

template<typename Container> 
typename Container::value_type barycentre_v2(const Container& c);

//Cartesien barycentre_v2(const std::vector<Cartesien>& vec_c);
//Polaire barycentre_v2(const std::vector<Polaire>& vec_p);

#endif