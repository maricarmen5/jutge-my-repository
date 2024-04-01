#include <queue>
#include <iostream>
#include "Punt.hpp"
using namespace std;

// Lectura i escriptura de cues de int

ostream& operator<<(ostream&, queue<Punt>);
/* Pre: cert */
/* Post: s'han escrit els valors enters de la cua
   al canal estàndard de sortida */

istream& operator>>(istream&, queue<Punt>&);
/* Pre: cert */
/* Post: la cua passa a tenir els valors enters llegits del canal 
   estàndard d'entrada */