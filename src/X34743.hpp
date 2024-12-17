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
    // d’equilibri (diferència entre l’altura fill esquerra i l’altura fill dret).
    void arbre_factors_equilibri();

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
    int arbre_factors_equilibri_aux(node* arrel);
};

// Aquí va la implementació del mètode arbre_factors_equilibri
template <typename T>
void Abin<T>::arbre_factors_equilibri() {
    if (_arrel != NULL) {
        int alturaFE = arbre_factors_equilibri_aux(_arrel->f_esq);
        int alturaFD = arbre_factors_equilibri_aux(_arrel->f_dret);
        _arrel->info = (T)(alturaFE-alturaFD);
    }
}

template <typename T>
int Abin<T>::arbre_factors_equilibri_aux(node* arrel) {
    int altura = 0;

    if (arrel != NULL) {
        int alturaFE = arbre_factors_equilibri_aux(arrel->f_esq);
        int alturaFD = arbre_factors_equilibri_aux(arrel->f_dret);
        arrel->info = (T)(alturaFD-alturaFE);

        altura = max(alturaFE, alturaFD) + 1;
    }

    return altura;
}