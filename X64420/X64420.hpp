#include <cstdlib>
#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Abin {
public:
    Abin(): _arrel(NULL) {};
    // Pre: cert
    // Post: el resultat és un arbre sense cap element
    Abin(Abin<T> &ae, const T &x, Abin<T> &ad);
    // Pre: cert
    // Post: el resultat és un arbre amb un element i dos subarbres

    // Les tres grans
    Abin(const Abin<T> &a);
    ~Abin();
    Abin<T>& operator=(const Abin<T>& a);

    // operador << d’escriptura
    template <class U> friend std::ostream& operator<<(std::ostream&, const Abin<U> &a);

    // operador >> de lectura
    template <class U> friend std::istream& operator>>(std::istream&, Abin<U> &a);

    // Modifica el contingut de l’arbre per tal de guardar a cada node el màxim dels nodes
    // del seu subarbre.
    void arbre_maxims();

private:
    struct node {
    node* f_esq;
    node* f_dret;
    T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);
    static void print_nodes(node* m, ostream &os, string d1);

    // Aquí va l’especificació dels mètodes privats addicionals
    void arbre_maxims_aux(node* arrel);
};

// Aquí va la implementació del mètode arbre_maxims
template <typename T>
void Abin<T>::arbre_maxims() {
    if (_arrel != NULL) arbre_maxims_aux(_arrel);
}

template <typename T>
void Abin<T>::arbre_maxims_aux(node* arrel) {
    if (arrel->f_esq != NULL) {
        arbre_maxims_aux(arrel->f_esq);
        if (arrel->info < arrel->f_esq->info) arrel->info = arrel->f_esq->info;
    }

    if (arrel->f_dret != NULL) {
        arbre_maxims_aux(arrel->f_dret);
        if (arrel->info < arrel->f_dret->info) arrel->info = arrel->f_dret->info;
    }
}