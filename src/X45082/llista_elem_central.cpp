#include <iostream>
#include <list>
using namespace std;

// Pre: l = L i la mida de L és senar
// Retorna l'element central de L
int elem_central_aux(const list<int> &l) 
{
    list<int>::const_iterator it1 = l.begin();
    list<int>::const_iterator it2 = l.end();
    --it2;

    int n = *it1;

    if (it1 != it2) {
        l.erase(it1);
        l.erase(it2);

        n = elem_central_aux(l);
    }

    return n;
}

int elem_central(const list<int> &l)
{
    list<int> li = l;
    int n = elem_central_aux(li);
    return n;
}