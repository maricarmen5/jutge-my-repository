#include "abin.hpp"

template <typename T>
list<T> Abin<T>::preordre() const { // cost quadràtic
    list<T> llista;
    node* actual = _arrel;
    while (actual != NULL) {
        llista.push_back(actual->info);
        if (actual->thread_esq) {
            while (actual != NULL and actual->thread_dret) {
                actual = actual->f_dret;
            }
            if (actual != NULL) actual = actual->f_dret;
        }
        else actual = actual->f_esq;
    }
    return llista;
}