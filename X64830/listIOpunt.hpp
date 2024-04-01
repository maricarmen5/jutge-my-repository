#include <list>
#include <iostream>
#include "Punt.hpp"
using namespace std;

// Lectura i escriptura de llistes de Punt

ostream& operator<<(ostream &os, const list<Punt> &l);
/* Pre: cert */
/* Post: s'han escrit els Punts de la llista l
   al canal estàndard de sortida */

istream& operator>>(istream &is, list<Punt> &l);
/* Pre: cert */
/* Post: la llista l passa a tenir els Punts llegits del canal 
   estàndard d'entrada */