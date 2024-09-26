#include "llista.hpp"

void Llista::fusiona_suma(Llista &l2, nat n) {
    nat suma = 0;
    nat i = 0;
    bool implicit = true;
    node* actual = _prim;

    while (actual != NULL and l2._prim != NULL) {
        if (implicit) suma += actual->info;
        else suma += l2._prim->info;
        ++i;

        if (i == n) {
            if (implicit) {
                l2._prim->ant = actual;
                actual = actual->seg;
                l2._prim->ant->seg = l2._prim;
                _ult = l2._prim;
            } else {
                actual->ant = l2._prim;
                l2._prim = l2._prim->seg;
                actual->ant->seg = actual;
                _ult = actual;
            }
            i = 0;
            implicit = not implicit;
        } else {
            if (implicit) {
                _ult = actual;
                actual = actual->seg;
            } else {
                _ult = l2._prim;
                l2._prim = l2._prim->seg;
            }
        }
    }
    
    while (actual != NULL) {
        if (_ult == l2._ult) {
            _ult->seg = actual;
            actual->ant = _ult;
        }
        _ult = actual;
        suma += actual->info;
        actual = actual->seg;
    }

    while (l2._prim != NULL) {
        if (_prim == NULL) _prim = l2._prim;
        if (_ult != NULL and _ult != l2._prim) {
            _ult->seg = l2._prim;
            l2._prim->ant = _ult;
        }
        _ult = l2._prim;
        suma += l2._prim->info;
        l2._prim = l2._prim->seg;
    }

    node* nodesuma = new node;
    nodesuma->info = suma;
    nodesuma->ant = NULL;
    if (_prim == NULL) {
        nodesuma->seg = NULL;
        _prim = nodesuma;
        _ult = nodesuma;
    } else {
        nodesuma->seg = _prim;
        _prim->ant = nodesuma;
        _prim = nodesuma;
    }

    _long += l2._long + 1;
    l2._long = 0;
    l2._ult = NULL;
}