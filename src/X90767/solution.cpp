#include "llista.hpp"

Llista::Llista(const vector<int> &v) {
    node* anterior = NULL;

    for (int i = 0; i < v.size(); ++i) {
        node* nou = new node;
        nou->info = v[i];
        nou->seg = NULL;

        if (anterior == NULL) {
            anterior = nou;
            _prim = nou;
        } else {
            anterior->seg = nou;
            anterior = anterior->seg;
        }
    }

    if (v.empty()) _prim = NULL;
    _long = v.size(); 
}