#include "llista.hpp"

Llista::Llista(const vector<int> &v) {
    _prim = new node;
    _prim->seg = NULL;

    node* anterior = NULL;
    for (int i = 0; i < v.size(); ++i) {
        node* nou = new node;
        nou->info = v[i];
        nou->seg = NULL;

        if (anterior == NULL) {
            anterior = nou;
            _prim->seg = nou;
        } else {
            anterior->seg = nou;
            anterior = anterior->seg;
        }
    }

    _long = v.size(); 
}