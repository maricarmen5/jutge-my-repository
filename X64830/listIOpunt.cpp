#include "listIOpunt.hpp"

// Lectura i escriptura de llistes de Punt

ostream& operator<<(ostream &os, const list<Punt> &l)
/* Pre: cert */
/* Post: s'han escrit els Punts de la llista l
   al canal estàndard de sortida */
{
    os << "[";

    for (list<Punt>::const_iterator it = l.begin(); it != l.end(); ++it) {
        if (it != l.begin()) os << ",";
        os << (*it);
    }

    os << "]" << endl;
    return os;
}

istream& operator>>(istream &is, list<Punt> &l)
/* Pre: cert */
/* Post: la llista l passa a tenir els Punts llegits del canal 
   estàndard d'entrada */
{
    int n;
    is >> n;
    list<Punt>::iterator it = l.begin();

    while (n > 0) {
        Punt e;
        is >> e;
        l.insert(it,e);
        --n;
    }

    return is;
}