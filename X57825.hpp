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

// Imprimeix la informació dels nodes en preordre, cada element en una nova línia i precedit per espais segons el nivell on està situat.
void preordre() const;

static const int ArbreInvalid = 400;

void arbre_simetric();
// Pre: cert
// Post: Modifica l’arbre amb el simètric de l’arbre original

private:
Arbre(): _arrel(NULL) {};
struct node {
    T info;        // Informació del node
    node* primf;   // Punter al primer fill
    node* seggerm; // Punter al següent germà
};
node* _arrel; // Punter a l’arrel de l’arbre
static node* copia_arbre(node* p);
static void destrueix_arbre(node* p) throw();
static void preordre(node *p, string pre);

// Aquí va l’especificació dels mètodes privats addicionals
void arbre_simetric_aux(node* arrel);
};

// Aquí va la implementació del mètode arbre_simetric i privats addicionals
template <typename T> 
void Arbre<T>::arbre_simetric() {
    if (_arrel != NULL) arbre_simetric_aux(_arrel);
}

template <typename T> 
void Arbre<T>::arbre_simetric_aux(node* arrel) { 
    node* fillActual = arrel->primf;
    node* nouPrimf = NULL;
    while (fillActual != NULL) {
        arbre_simetric_aux(fillActual);
        node* seggerm = fillActual->seggerm;
        if (nouPrimf == NULL) fillActual->seggerm = NULL;
        else fillActual->seggerm = nouPrimf;
        nouPrimf = fillActual;
        fillActual = seggerm;
    }
    arrel->primf = nouPrimf;
}