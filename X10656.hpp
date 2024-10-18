#include <cstdlib>
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

// Col·loca l’Arbre donat com a primer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
void afegir_fill(Arbre<T> &a);

static const int ArbreInvalid = 400;

// Indica quants nodes de grau n té.
nat quants_grau(nat n) const;

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
nat quants_grau_aux(nat n, node* arrel) const;
};

// Aquí va la implementació del mètode quants_grau
template <typename T>	
nat Arbre<T>::quants_grau(nat n) const {
    nat nodesGrauN = quants_grau_aux(n, _arrel);
    return nodesGrauN;
}

template <typename T>	
nat Arbre<T>::quants_grau_aux(nat n, node* arrel) const {
    nat nodesGrauN = 0;
    if (arrel != NULL) {
        nat numFills = 0;
        node* fillActual = arrel->primf;
        while (fillActual != NULL) {
            nodesGrauN += quants_grau_aux(n, fillActual);
            ++numFills;
            fillActual = fillActual->seggerm;
        }
        if (numFills == n) ++nodesGrauN;
    }
    return nodesGrauN;
}