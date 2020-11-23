#ifndef _VECTEUR03_HPP_
#define _VECTEUR03_HPP_

#include "complexe.hpp"
#include <stdexcept>
#include <iterator>
#include <vector>
#include <functional>

class Vecteur 
{
  private:
    unsigned taille_;
    complexe_t* tableau_;
    
    using iterator = complexe_t*;

  public:
    unsigned getTaille(void) const { return taille_; }

    complexe_t& operator[](unsigned i) 
    {
      if (i<taille_) 
      {
        return tableau_[i];
      }

      throw std::out_of_range("");
    }

    const complexe_t& operator[](unsigned i) const 
    {
      if (i<taille_)
      { 
        return tableau_[i];
      }

      throw std::out_of_range("");
    }

    explicit Vecteur(unsigned t = 10) : taille_(t),tableau_(new complexe_t[taille_]) {}

    Vecteur(const Vecteur & v) : taille_(v.taille_),tableau_(new complexe_t[taille_]) 
    {
      for(unsigned i = 0; i<taille_; ++i) 
      {
        tableau_[i] = v[i];
      }
    }

    ~Vecteur(void) 
    { 
      if (tableau_)
      { 
        delete [] tableau_;
      } 
    }

    Vecteur & operator=(const Vecteur & v) 
    {
      if(this!=&v) 
      {
          if(taille_!=v.taille_) 
          {
            throw std::length_error("");
          }

          for(unsigned i = 0; i<v.taille_; ++i) 
          {
            tableau_[i] = v[i];
          }
      }

      return *this;
    }

    Vecteur(Vecteur&& v) : taille_(v.taille_), tableau_(v.tableau_)
    {
      v.taille_ = 0;
      v.tableau_ = nullptr;
    }

    Vecteur& operator=(Vecteur&& v)
    {
      std::cout << "*********MOVE**********" << std::endl;

      std::swap(taille_, v.taille_);
      std::swap(tableau_, v.tableau_);

      return *this;
    }

    iterator begin()
    {
      return &tableau_[0];
    }

    iterator end()
    {
      return &tableau_[taille_];
    }
};

inline std::ostream & operator<<(std::ostream & flux,const Vecteur & v) 
{
  for (unsigned i = 0; i<v.getTaille(); ++i) 
  {
      flux << v[i] << " ";
  }

  return flux;
}

inline Vecteur operator+(const Vecteur & v1,const Vecteur & v2) 
{
  Vecteur v;

  for(unsigned i = 0; i<v1.getTaille(); ++i) 
  {
    v[i] = v1[i] + v2[i];
  }

  return v;
}

inline Vecteur operator*(const Vecteur & v1,const Vecteur & v2) 
{
  Vecteur v;

  for(unsigned i = 0; i<v1.getTaille(); ++i) 
  {
    v[i] = v1[i] * v2[i];
  }

  return v;
}

template<typename F> 
Vecteur operation(const Vecteur& v1,const Vecteur& v2, F&& op)
{
  return op(v1, v2);
}

Vecteur operation(const Vecteur& v1,const Vecteur& v2, const std::function<Vecteur(const Vecteur& v1,const Vecteur& v2)>& op)
{
  return op(v1, v2);
}

#endif