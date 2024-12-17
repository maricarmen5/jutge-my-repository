#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    nat suma = 0;
    nat i = 0;
    bool implicit = true;
    node* actual = _prim->seg;
    node* actual2 = l2._prim->seg;

    while (actual != _prim and actual2 != l2._prim) {
        if (implicit) suma += actual->info;
        else suma += actual2->info;
        ++i;

        if (i == n) {
            if (implicit) {
                actual2->ant = actual;
                actual = actual->seg;
                actual2->ant->seg = actual2;
            } else {
                actual->ant = actual2;
                actual2 = actual2->seg;
                actual->ant->seg = actual;
            }
            i = 0;
            implicit = not implicit;
        } 
        else if (implicit) actual = actual->seg;
        else actual2 = actual2->seg;
    }

    if (actual != _prim and l2._long != 0 and actual2->ant->seg != actual) {
        actual2->ant->seg = actual;
        actual->ant = actual2->ant;
    }
    while (actual != _prim) {
        suma += actual->info;
        actual = actual->seg;
    }

    if ((actual->ant->seg != actual2 or _long == 0) and  l2._long != 0) {
        actual->ant->seg = actual2;
        actual2->ant = actual->ant;
    }
    while (actual2 != l2._prim) {
        suma += actual2->info;
        actual2 = actual2->seg;
    }

    node* nodesuma = new node;
    nodesuma->info = suma;
    nodesuma->ant = _prim;
    nodesuma->seg = _prim->seg;
    nodesuma->seg->ant = nodesuma;
    _prim->seg = nodesuma;
    if (actual2->ant->seg == l2._prim and l2._long != 0) {
        actual2->ant->seg = _prim;
        _prim->ant = actual2->ant;
    }
    
    _long += l2._long + 1;
    l2._long = 0;
    l2._prim->seg = l2._prim;
    l2._prim->ant = l2._prim;
}