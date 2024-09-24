#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    nat suma = 0;
    nat i = 0;
    bool implicit = true;
    node* actual = _prim;
    node* anterior = NULL;

    while (actual != NULL and l2._prim != NULL) {
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

    while (actual != NULL) {
        if (anterior != NULL) {
            anterior->seg = actual;
            anterior = anterior->seg;
        }
        suma += actual->info;
        actual = actual->seg;
    }

    while (l2._prim != NULL) {
        if (anterior != NULL) {
            anterior->seg = l2._prim;
            anterior = anterior->seg;
        }
        else {
            _prim = l2._prim;
            anterior = l2._prim;
        }
        suma += l2._prim->info;
        l2._prim = l2._prim->seg;
    }

    node* nodesuma = new node;
    nodesuma->info = suma;
    nodesuma->seg = _prim;
    _prim = nodesuma;

    _long += l2._long + 1;
    l2._long = 0;
}