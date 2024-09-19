#include "cua.hpp"

cua::cua(const vector<int> &v) {
    node* primer = NULL;
    node* anterior = NULL;

    for (int i = 0; i < v.size(); ++i) {
        node* nou = new node;
        nou->info = v[i];
        nou->seg = NULL;

        if (anterior == NULL) {
            anterior = nou;
            primer = nou;
        } else {
            anterior->seg = nou;
            anterior = anterior->seg;
        }
        
        if (i == v.size()-1) {
            _ult = nou;
            _ult->seg = primer;
        }
    }

    if (v.empty()) _ult = NULL;
    _long = v.size();
}