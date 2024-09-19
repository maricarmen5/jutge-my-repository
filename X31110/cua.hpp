#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;
 
template <typename T>
class cua { // Cua no circular en memòria dinàmica
    public:
    cua();
    // Construeix una cua buida.
 
    ~cua();
    // Destrueix el p.i.
 
    cua(const vector<int> &v);
    // Crea cua amb els elements de v amb el mateix ordre.
 
    nat longitud() const;
    // Retorna el nombre d’elements del p.i.
 
    void mostra() const;
    // Mostra el p.i. pel canal estàndard de sortida.
 
    void fusiona(const cua<T> &c2);
    // Pre: Les cues del p.i. i c2 estan ordenades de menor a major
    // Post: Al p.i. se li han afegit els elements de c2 ordenadament. c2 no es modifica
 
    private:
    struct node {
        T info;
        node* seg;
    };
    node* _pri; // Apunta al primer element de la cua
    node* _ult; // Apunta al darrer element de la cua
    nat _mida;
 
    // Aquí va l’especificació dels mètodes privats addicionals
};

template <typename T>
// Aquí va la implementació del mètode públic fusiona i privats addicionals
void cua<T>::fusiona(const cua<T> &c2) { // cost lienal = n1 + n2
    node* actual = _pri;
    node* anterior = NULL;
    node* actual2 = c2._pri;

    while (actual != NULL and actual2 != NULL) { // cost = max(n1, n2)
        if (actual2->info < actual->info) {
            node* nou = new node;   
            nou->info = actual2->info;
            nou->seg = actual;

            if (anterior == NULL) {
                _pri = nou;
                anterior = _pri;
            }
            else {
                anterior->seg = nou;
                anterior = anterior->seg;
            }

            actual2 = actual2->seg;
            ++_mida;
        }
        else {
            anterior = actual;
            actual = actual->seg;
        }
    }

    while (actual2 != NULL) { // cost = n2
        node* nou = new node;
        nou->info = actual2->info;
        nou->seg = actual2->seg;

        if (anterior == NULL) {
            _pri = nou;
            anterior = _pri;
        }
        else {
            anterior->seg = nou;
            anterior = anterior->seg;
        }

        ++_mida;
        _ult = anterior;
        actual2 = actual2->seg;
    }
}