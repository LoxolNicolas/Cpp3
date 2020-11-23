#ifndef _VECTEUR03_HPP_
#define _VECTEUR03_HPP_

#include "complexe.hpp"
#include <stdexcept>

class Vecteur 
{
  private:
    unsigned taille_;
    complexe_t* tableau_;

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

  for (unsigned i = 0; i<v1.getTaille(); ++i) 
  {
    v[i] = v1[i] * v2[i];
  }

  return v;
}

#endif