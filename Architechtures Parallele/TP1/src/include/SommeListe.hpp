#ifndef SommeListe_hpp
#define SommeListe_hpp

/**
 * @class SommeListe SommeListe.hpp
 *
 * Template récursif permettant de calculer la somme des entiers d'une liste
 * non vide de taille variable.
 */
template< int ... liste >
class SommeListe;

// Spécialisation pour une liste contenant au moins deux entiers. Nous adoptons
// les codes du paradigme fonctionnel : L = [ car | cdr ].
template< int car, int ... cdr >
class SommeListe< car, cdr ... > {
public:

  // S([ car | cdr ]) = car + S(cdr).
  enum : long { value = car + SommeListe< cdr ... >::value } ;

}; // SommeListe< car, cdr >

// Spécialisation pour une liste d'exactement un entier.
template< int car >
class SommeListe< car > {
public:

  // S([car | nil ]) = car.
  enum : long { value = car };

}; // SommeListe< car>

#endif
