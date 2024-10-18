#include <cstdlib>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename T>
class Arbre {

public:
// Construeix un Arbre format per un únic node que conté a x.
Arbre(const T &x);

// Tres grans.
Arbre(const Arbre<T> &a);
Arbre& operator=(const Arbre<T> &a);
~Arbre() throw();

// Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
void afegir_darrer_fill(Arbre<T> &a);

static const int ArbreInvalid = 400;

// Retorna un vector amb les sumes de tots els elements de cada nivell.
vector<T> sumes_nivells() const;

private:
Arbre(): _arrel(NULL) {};
struct node {
    T info;
    node* primf;
    node* seggerm;
};
node* _arrel;
static node* copia_arbre(node* p);
static void destrueix_arbre(node* p) throw();

// Aquí va l’especificació dels mètodes privats addicionals
void sumes_nivells_aux(node* arrel, int nivell, vector<T>& sumaNivells) const;
};

// Aquí va la implementació del mètode sumes_nivells
template <typename T>
vector<T> Arbre<T>::sumes_nivells() const {
    vector<T> sumaNivells;
    if (_arrel != NULL) {
        sumaNivells.push_back(_arrel->info);
        sumes_nivells_aux(_arrel, 1, sumaNivells);
    }
    return sumaNivells;
}

template <typename T>
void Arbre<T>::sumes_nivells_aux(node* arrel, int nivell, vector<T>& sumaNivells) const {
    node* fillActual = arrel->primf;
    if (fillActual != NULL and (int)sumaNivells.size() < nivell+1) sumaNivells.push_back(0);
    while(fillActual != NULL) {
        sumes_nivells_aux(fillActual, nivell+1, sumaNivells);
        sumaNivells[nivell] += fillActual->info;
        fillActual = fillActual->seggerm;
    }
}
