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

    // Modifica el contingut de l’arbre per tal de guardar a cada node el factor
    // de pes (diferència entre quantitat nodes fill esquerra i quantitat nodes fill dret).
    void arbre_factors_pes();

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
    int arbre_factors_pes_aux(node* arrel);
};

// Aquí va la implementació del mètode arbre_factors_pes
template <typename T>
void Abin<T>::arbre_factors_pes() {
    if (_arrel != NULL) {
        int nodesFE = arbre_factors_pes_aux(_arrel->f_esq);
        int nodesFD = arbre_factors_pes_aux(_arrel->f_dret);
        _arrel->info = nodesFE-nodesFD;
    }
}

template <typename T>
int Abin<T>::arbre_factors_pes_aux(node* arrel) {
    int nodes = 0;
    if (arrel != NULL) {
        int nodesFE = arbre_factors_pes_aux(arrel->f_esq);
        int nodesFD = arbre_factors_pes_aux(arrel->f_dret);
        arrel->info = nodesFE-nodesFD;
        nodes = 1+nodesFE+nodesFD;
    }
    return nodes;
}