#include "llista.hpp"

Llista::Llista(const vector<int> &v) {
    _prim = new node;
    _prim->ant = _prim;
    _prim->seg = _prim;

    node* anterior = _prim;
    for (int i = 0; i < v.size(); ++i) {
        node* nou = new node;
        nou->info = v[i];
        anterior->seg = nou;
        nou->ant = anterior;

        anterior = nou;
    }

    if (not v.empty()) {
        anterior->seg = _prim;
        _prim->ant = anterior;
    }
    
    _long = v.size(); 
}