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

// Imprimeix la informació dels nodes en preodre, cada element en una nova línia i
// precedit per espais segons el nivell on està situat.
void preordre() const;

static const int ArbreInvalid = 400;

// Elimina tots els nodes de grau 0 de l’arbre.
void elimina_grau0();

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
static void preordre(node *p, string pre);

// Aquí va l’especificació dels mètodes privats addicionals
void elimina_grau0_aux(node* arrel);
};

// Aquí va la implementació del mètode elimina_grau0
template <typename T>	
void Arbre<T>::elimina_grau0() {
    if (_arrel != NULL) {
        if (_arrel->primf == NULL) {
            node* aux = _arrel;
            _arrel = NULL;
            delete aux;
        }
        else elimina_grau0_aux(_arrel);
    }
}

template <typename T>	
void Arbre<T>::elimina_grau0_aux(node* arrel) {
    node* fillActual = arrel->primf;
    node* ultFill = NULL;
    while (fillActual != NULL) {
        if (fillActual->primf == NULL) {
            node* aux = fillActual;
            fillActual = fillActual->seggerm;
            delete aux;
            if (ultFill == NULL) arrel->primf = fillActual;
            else ultFill->seggerm = fillActual;
        } else {
            elimina_grau0_aux(fillActual);
            ultFill = fillActual;
            fillActual = fillActual->seggerm;
        }
    }
}