#ifndef _COMPLEXE_HPP_
#define _COMPLEXE_HPP_

#include <iostream>
#include "mouchard.hpp"

struct Complexe 
{
    double reel;
    double imaginaire;

    Complexe(double r = 0.0,double i = 0.0) : reel(r), imaginaire(i) {}
};

using complexe_t = Mouchard<Complexe>;
//using complexe_t = Complexe;

inline complexe_t operator+(const complexe_t& a, const complexe_t& b) 
{
    return complexe_t(a.reel + b.reel, a.imaginaire + b.imaginaire);
}

inline complexe_t operator*(const complexe_t& a, const complexe_t& b) 
{
    return complexe_t(a.reel * b.reel - a.imaginaire * b.imaginaire , a.reel * b.imaginaire + a.imaginaire * b.reel);
}

inline std::ostream & operator<<(std::ostream& flux, const complexe_t& c) 
{
    flux << "(" << c.reel << ";" << c.imaginaire << ")";

    return flux;
}

struct ComparateurComplexe 
{
    bool operator() (const complexe_t& a,const complexe_t& b) const 
    {
        return (a.reel < b.reel || (a.reel == b.reel && a.imaginaire < b.imaginaire));
    }
};

#endif