#include <cstddef>
#include <vector>
#include <iostream>
using namespace std;
typedef unsigned int nat;

class Llista {
// Llista doblement encadenada, no circular i sense fantasma.

public:
    Llista();
    // Pre: True
    // Post: El p.i. és una llista buida.

    Llista(const vector<int> &v);
    // Pre: True
    // Post: El p.i. conté els elements de v amb el mateix ordre.

    ~Llista();
    // Post: Destrueix els elements del p.i.

    nat longitud() const;
    // Pre: True
    // Post: Retorna el nombre d’elements del p.i.

    void mostra() const;
    // Pre: True
    // Post: Mostra el p.i. pel canal estàndard de sortida.

    void mostra_invertida() const;
    // Pre: True
    // Post: Mostra el p.i. en ordre invers pel canal estàndard de sortida.

    void ordena();
    // Pre: True
    // Post: S’han ordenat eficientment els elements del p.i. de major a menor

private:
    struct node {
    int info;  // Informació del node
    node *seg; // Punter al següent element
    node *ant; // Punter a l’anterior element
    };
    node *_prim; // Punter al primer element
    node *_ult;  // Punter a l’últim element
    nat _long;   // Nombre d’elements

    // Aquí va l’especificació dels mètodes privats addicionals
    node* mergeSort(node* p1, int size);

    node* partir(node* p1, int size);

    node* fusionar(node* p1, node* p2);
};

// Aquí va la implementació del mètode ordena i privats addicionals
void Llista::ordena() { // cost total: theta(nlogn)
    _prim = mergeSort(_prim, _long);

    node* actual = _prim;
    _ult = NULL;
    while (actual != NULL) { // cost lineal
        _ult = actual;
        actual = actual->seg;
    }
}

Llista::node* Llista::fusionar(node* p1, node* p2) { // cost lineal
    node* p = p1;
    if (p1 == NULL) p = p2;
    else if (p1 != NULL and p2 != NULL) {
        node* q = NULL;
        if (p2->info < p1->info) {
            p = p1;
            q = fusionar(p1->seg, p2);
        } else {
            p = p2;
            q = fusionar(p1, p2->seg);
        }

        if (q != NULL) q->ant = p;
        p->seg = q;
        p->ant = NULL;
    }
    return p;
}

Llista::node* Llista::mergeSort(node* p1, int size) { // cost logarítmic
    if (p1 != NULL and p1->seg != NULL) {
        int meitat = size/2;
        node* p2 = partir(p1, meitat); // primer de la llista dos (segona meitat)
        p1 = mergeSort(p1, meitat);
        p2 = mergeSort(p2, size-meitat);
        p1 = fusionar(p1, p2);
    }
    return p1;
}

Llista::node* Llista::partir(node* p1, int size) { // cost lineal
    node* p2 = p1;
    for (int i = 0; i < size; ++i) p2 = p2->seg;
    p2->ant->seg = NULL; // partim la llista: p2->ant és l'últim element de la llista 1
    return p2;
}