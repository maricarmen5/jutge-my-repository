#include <iostream>
#include <sstream>
#include <vector>
#include <cstddef>
using namespace std;
typedef unsigned int nat;

class Llista {
// Llista simplement encadenada, sense fantasma i circular.

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

    void duplica_capicua();
    // Pre: True
    // Post: Es dupliquen tots els elements del p.i. obtenint una llista capicua
    // Exemple: [2 5 3 8 4] => [2 5 3 8 4 4 8 3 5 2]

private:
    struct node {
    int info;  // Informació del node
    node *seg; // Punter al següent element
    };
    node *_prim; // Punter al primer element
    nat _long;   // Nombre d’elements

    // Aquí va l’especificació dels mètodes privats addicionals

};

// Aquí va la implementació del mètode duplica_capicua i dels privats addicionals
void Llista::duplica_capicua() { // cost lineal: theta(n)
    node* actual = _prim;
    node* ultim = NULL;
    node* revessatPrim = NULL;
    node* revessatUltim = NULL;
    for (nat i = 0; i < _long; ++i) {
        node* nou = new node;
        nou->info = actual->info;
        nou->seg = NULL;
        ultim = actual;
        actual = actual->seg;
        if (revessatPrim == NULL) revessatUltim = nou;
        else nou->seg = revessatPrim;
        revessatPrim = nou;
    }
    if (revessatPrim != NULL) {
        ultim->seg = revessatPrim;
        revessatUltim->seg = _prim;
    }
    _long *= 2;
}