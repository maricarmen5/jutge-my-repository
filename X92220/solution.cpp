#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    nat suma = 0;
    nat i = 0;
    bool implicit = true;
    node* actual = _prim->seg;
    node* anterior = NULL;
    node* l2prim = l2._prim;
    l2._prim = l2._prim->seg;

    while (actual != _prim and l2._prim != l2prim) {
        if (implicit) suma += actual->info;
        else suma += l2._prim->info;
        ++i;

        if (i == n) {
            if (implicit) {
                anterior = actual;
                actual = actual->seg;
                anterior->seg = l2._prim;
            } else {
                anterior = l2._prim;
                l2._prim = l2._prim->seg;
                anterior->seg = actual;
            }
            i = 0;
            implicit = not implicit;
        } else {
            if (implicit) {
                anterior = actual;
                actual = actual->seg;
            } else {
                anterior = l2._prim;
                l2._prim = l2._prim->seg;
            }
        }
    }

    while (actual != _prim) {
        if (anterior != NULL) {
            anterior->seg = actual;
            anterior = anterior->seg;
        }
        else anterior = actual;
        suma += actual->info;
        actual = actual->seg;
    }

    while (l2._prim != l2prim) {
        if (anterior != NULL) {
            anterior->seg = l2._prim;
            anterior = anterior->seg;
        }
        else {
            _prim->seg = l2._prim;
            anterior = l2._prim;
        }
        suma += l2._prim->info;
        l2._prim = l2._prim->seg;
    }

    node* nodesuma = new node;
    nodesuma->info = suma;
    nodesuma->seg = _prim->seg;
    _prim->seg = nodesuma;
    if (anterior == NULL) nodesuma->seg = _prim;
    else anterior->seg = _prim;

    _long += l2._long + 1;
    l2._long = 0;
    l2._prim = l2prim;
    l2prim->seg = l2prim;
}