#include <iostream>
#include <cstdlib>
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

    // Escriu una línia amb els elements del nivell i-èssim, d’esquerra 
    // a dreta. Cada element ha de sortir precedit d’un espai.
    void nivell(nat i) const;

private:
    struct node {
    node* f_esq;
    node* f_dret;
    T info;
    };
    node* _arrel;
    static node* copia_nodes(node* m);
    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
    void nivell_aux(nat i, nat nivell, node* a) const;
};

// Aquí va la implementació del mètode nivell
template <typename T>
void Abin<T>::nivell(nat i) const {
    nivell_aux(i, 0, _arrel);
}

template <typename T>
void Abin<T>::nivell_aux(nat i, nat nivell, node* a) const {
    if (a != NULL) {
        if (nivell < i) {
            nivell_aux(i, nivell+1, a->f_esq);
            nivell_aux(i, nivell+1, a->f_dret);
        } 
        else if (nivell == i) cout << ' ' << a->info;
    }
}