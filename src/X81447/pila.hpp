#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;
 
template <typename T>
class pila { // pila en memòria dinàmica
   public:
    pila();
    // Crea pila buida
 
    ~pila();
    // Destrueix el p.i.
 
    pila(const vector<int> &v);
    // Crea pila amb els elements de v amb el mateix ordre.
 
    nat longitud() const;
    // Retorna el nombre d’elements del p.i.
 
    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.
 
    void fusiona(const pila<T> &p2);
     // Pre: Les piles del p.i. i p2 estan ordenades de menor a major
     // Post: Al p.i. se li han afegit els elements de p2 ordenadament. p2 no es modifica
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
};

template <typename T>
// Aquí va la implementació del mètode públic fusiona i privats addicionals
// Cost Lineal: n1 + n2 en el pitjor dels casos
void pila<T>::fusiona(const pila<T> &p2) {
    node* actual = _cim;
    node* anterior = NULL;
    node* actual2 = p2._cim;

    while (actual != NULL and actual2 != NULL) { // cost lineal: n1 + n2
        if (actual2->info < actual->info) {
            node* nou = new node;
            nou->info = actual2->info;
            nou->seg = actual;

            if (anterior == NULL) {
                _cim = nou;
                anterior = _cim;
            }
            else {
                anterior->seg = nou;
                anterior = anterior->seg;
            }

            ++_mida;
            actual2 = actual2->seg;
        }
        else {
            anterior = actual;
            actual = actual->seg;
        }
    }

    while (actual2 != NULL) { // cost lineal: n2
        node* nou = new node;
        nou->info = actual2->info;
        nou->seg = actual2->seg;

        if (anterior == NULL) {
            _cim = nou;
            anterior = _cim;
        }
        else {
            anterior->seg = nou;
            anterior = anterior->seg;
        }
     
        ++_mida;
        actual2 = actual2->seg;
    }
}
