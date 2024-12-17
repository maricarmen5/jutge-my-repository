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

// Col·loca l’Arbre donat com a darrer fill de l’arrel de l’arbre sobre el que s’aplica el mètode i l’arbre a queda invalidat; després de fer b.afegir_fill(a), a no és un arbre vàlid.
void afegir_darrer_fill(Arbre<T> &a);

// Imprimeix la informació dels nodes en preodre, cada element en una nova línia i precedit per espais segons el nivell on està situat.
void preordre() const;

static const int ArbreInvalid = 400;

// Per cada fulla afegeix un nou fill que conté el màxim de tots els elements del camí que va de l’arrel a la fulla.
void crea_fills_maxims_camins();

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
void crea_fills_maxims_camins_aux(node* arrel, T max);
};

// Aquí va la implementació del mètode crea_fills_maxims_camins i dels privats addicionals
template <typename T>
void Arbre<T>::crea_fills_maxims_camins() {
    if (_arrel != nullptr) crea_fills_maxims_camins_aux(_arrel, _arrel->info);
}

template <typename T>
void Arbre<T>::crea_fills_maxims_camins_aux(node* arrel, T max) {
    node* fillActual = arrel->primf;
    if (fillActual == nullptr) {
        arrel->primf = new node;
        arrel->primf->info = max;
        arrel->primf->primf = nullptr;
        arrel->primf->seggerm = nullptr;
    } else {
        while (fillActual != nullptr) {
            T maxActual = max;
            if (maxActual < fillActual->info) maxActual = fillActual->info;
            crea_fills_maxims_camins_aux(fillActual, maxActual);
            fillActual = fillActual->seggerm;
        }
    }
}