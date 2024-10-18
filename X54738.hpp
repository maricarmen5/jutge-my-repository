#include <cstdlib>
#include <string>
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

// Comprova que el contingut de cada node coincideix amb el seu grau
bool es_arbre_compta_graus();

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
bool es_arbre_compta_graus_aux(node* arrel);
};

// Aquí va la implementació del mètode es_arbre_compta_graus
template <typename T>
bool Arbre<T>::es_arbre_compta_graus() {
    bool coincideixInfoGrau = true;
    if (_arrel != NULL) coincideixInfoGrau = es_arbre_compta_graus_aux(_arrel);
    return coincideixInfoGrau;
}

template <typename T>
bool Arbre<T>::es_arbre_compta_graus_aux(node* arrel) {
    bool coincideixInfoGrau = true;
    int numFills = 0;
    node* fillActual = arrel->primf;
    while (fillActual != NULL and coincideixInfoGrau) {
        coincideixInfoGrau = es_arbre_compta_graus_aux(fillActual);
        ++numFills;
        fillActual = fillActual->seggerm;
    }
    if ((int)arrel->info != numFills) coincideixInfoGrau = false;
    return coincideixInfoGrau;
}