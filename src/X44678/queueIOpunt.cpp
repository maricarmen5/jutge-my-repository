#include "queueIOpunt.hpp"
#include "Punt.hpp"

// Lectura i escriptura de cues de int

ostream& operator<<(ostream& os, queue<Punt> q)
/* Pre: cert */
/* Post: s'han escrit els enters de la cua q
   al canal estàndard de sortida */
{   
    os << "<";
    int n = q.size();
    for (int i = 0; i < n; ++i) {
        os << q.front() << "|";
        q.pop();
    }
    os << "<" << endl;
    return os;
}

istream& operator>>(istream &is, queue<Punt> &q)
/* Pre: cert */
/* Post: la cua q passa a tenir els enters llegits pel canal 
   estàndard d'entrada */
{
    int n;
    cin >> n;
    for (int i = 0; i < n ; ++i) {
        Punt e;
        is >> e;
        q.push(e);
    }
    return is;
}