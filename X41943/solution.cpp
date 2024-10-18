#include "llista.hpp"

void Llista::duplica_positius_elimina_negatius() {
    node* ultim = NULL;
    node* actual = _prim;
    while (actual != NULL) {
        if (0 < actual->info) {
            node* nou = new node;
            nou->info = actual->info;
            nou->seg = actual;
            if (ultim == NULL) _prim = nou;
            else ultim->seg = nou;
            ultim = actual;
            actual = actual->seg;
            ++_long;
        } else if (actual->info < 0){
            node* aux = actual;
            actual = actual->seg;
            delete aux;
            if (ultim == NULL) _prim = actual;
            else ultim->seg = actual;
            --_long;
        } else {
            ultim = actual;
            actual = actual->seg;
        }
    }
}