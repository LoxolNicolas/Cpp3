#ifndef _MOUCHARD_HPP_
#define _MOUCHARD_HPP_

#include <iostream>
#include <type_traits>
#include <utility>

template<class T> using type_base_t = typename std::remove_reference<typename std::remove_const<T>::type>::type;

template<class T1,class T2> using meme_type_t = std::is_same< type_base_t<T1>,type_base_t<T2> >;

template<class T> class Mouchard : public T 
{
  private:
    static unsigned long nbAffectation_;
    static unsigned long nbConstruction_;
    static unsigned long nbCopie_;
    static unsigned long nbMouvement_;

  public:
    static unsigned long getNbAffectation(void) { return nbAffectation_; }
    static unsigned long getNbConstruction(void) { return nbConstruction_; }
    static unsigned long getNbCopie(void) { return nbCopie_; }
    static unsigned long getNbMouvement(void) { return nbMouvement_; }

    Mouchard(void) 
    { 
      ++nbConstruction_; 
    }

    Mouchard(const Mouchard & x) : T(x) 
    {
      ++nbConstruction_;
      ++nbCopie_;
    }

    Mouchard(Mouchard && x) : T(std::move(x)) 
    {
      ++nbConstruction_;
      ++nbMouvement_;
    }

    Mouchard & operator=(const Mouchard & x) 
    {
      ++nbAffectation_;
      ++nbCopie_;
      T::operator=(x);
      return *this;
    }

    Mouchard & operator=(Mouchard && x) 
    {
      ++nbAffectation_;
      ++nbMouvement_;
      T::operator=(std::move(x));
      return *this;
    }

    template <class X,class... PACK, class = typename std::enable_if< !meme_type_t< X,Mouchard<T> >::value>::type>
    Mouchard(X && x,PACK &&... pack) : T(std::forward<X>(x),std::forward<PACK...>(pack...)) 
    {
      ++nbConstruction_;
    }

    template <class X, class = typename std::enable_if< !meme_type_t< X,Mouchard<T> >::value>::type>
    Mouchard & operator=(X && x) 
    {
      ++nbAffectation_;
      T::operator=(std::forward<X>(x));
      return *this;
    }

    static void stats(void) 
    {
      std::cout << "affectations = " << nbAffectation_ << " ; " << "constructions = " << nbConstruction_ << " ; " << "copies = " << nbCopie_ << " ; " << "mouvements = " << nbMouvement_ << std::endl;
    }
};

template <class T> unsigned long Mouchard<T>::nbAffectation_  = 0;
template <class T> unsigned long Mouchard<T>::nbConstruction_ = 0;
template <class T> unsigned long Mouchard<T>::nbCopie_        = 0;
template <class T> unsigned long Mouchard<T>::nbMouvement_    = 0;

#endif