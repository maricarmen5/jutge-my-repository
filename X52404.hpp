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

    // Modifica el contingut de l’arbre per tal de guardar a cada node la suma dels
    // nodes del seu subarbre.
    void arbre_sumes();

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
    void arbre_sumes_aux(node* a);
};

// Aquí va la implementació del mètode arbre_sumes
template <typename T>
void Abin<T>::arbre_sumes() {
    if (_arrel != NULL) arbre_sumes_aux(_arrel);
}

template <typename T>
void Abin<T>::arbre_sumes_aux(node* a) {
    if (a->f_esq != NULL) {
        arbre_sumes_aux(a->f_esq);
        a->info += a->f_esq->info;
    }
    if (a->f_dret != NULL) {
        arbre_sumes_aux(a->f_dret);
        a->info += a->f_dret->info;
    }
}