#include <cstddef>
#include <iostream>
using namespace std;
typedef unsigned int nat;

class Llista {
// Llista simplement encadenada, sense fantasma i circular.

public:
Llista();
// Pre: True
// Post: El p.i. és una llista buida.

Llista(nat n);
// Pre: n > 0
// Post: El p.i. és una llista de n elements que contenen els naturals de 1 a n ordenadament.

~Llista();
// Post: Destrueix els elements del p.i.

nat longitud() const;
// Pre: True
// Post: Retorna el nombre d’elements del p.i.

void mostra() const;
// Pre: True
// Post: Mostra el p.i. pel canal estàndard de sortida.

void josephus(nat k);
// Pre: k > 0, p.i. conté un o més elements
// Post: Al p.i. s’han eliminat un de cada k elements fins que només en queda un.

private:
struct node {
    int info;  // Informació del node
    node *seg; // Punter al següent element
};
node *_prim; // Punter al primer element
nat _long;   // Nombre d’elements

// Aquí va l’especificació dels mètodes privats addicionals
node* obteUltim();
};

// Aquí va la implementació dels mètodes Llista(nat n) i josephus i privats addicionals
Llista::Llista(nat n) { // cost lineal: theta(n)
    _prim = nullptr;
    node* ultim = nullptr;

    for (nat i = 1; i <= n; ++i) {
        node* nou = new node;
        nou->info = i;
        nou->seg = nullptr;

        if (ultim == nullptr) _prim = nou;
        else ultim->seg = nou;
        ultim = nou;
    }
    if (ultim != nullptr) ultim->seg = _prim;

    _long = n;
}

// Pre: p.i. té almenys un element
// Retorna l'ultim node de la llista o l'element fantasma en cas de que la llista sigui buida
Llista::node* Llista::obteUltim() { // cost lineal: theta(n)
    node* ultim = _prim;
    while (ultim->seg != _prim) ultim = ultim->seg;
    return ultim;
}

void Llista::josephus(nat k) { // cost lineal en funció de n i també en funció de k: theta(n+nk)
    node* actual = _prim;
    node* ultim = obteUltim(); // theta(n)
    nat i = 1;
    while (_prim->seg != _prim) { // theta(nk)
        if (i%k == 0) {
            i = 1;
            node* aux = actual;
            if (_prim == actual) _prim = actual->seg;
            ultim->seg = actual->seg;
            actual = actual->seg;
            delete aux;
            --_long;
        } else {
            ++i;
            ultim = actual;
            actual = actual->seg;
        }
    }
}