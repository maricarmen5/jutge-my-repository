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

// Retorna un vector amb les sumes de tots els elements de cada camí que va de l’arrel a una fulla.
vector<T> sumes_camins() const;

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
void sumes_camins_aux(node* arrel, T suma, vector<T>& v) const;
};

// Aquí va la implementació del mètode sumes_camins
template <typename T>
vector<T> Arbre<T>::sumes_camins() const {
    vector<T> resultat;
    if (_arrel != nullptr) sumes_camins_aux(_arrel, _arrel->info, resultat);
    return resultat;
}

template <typename T>
void Arbre<T>::sumes_camins_aux(node* arrel, T suma, vector<T>& v) const {
    node* fillActual = arrel->primf;
    if (fillActual == nullptr) v.push_back(suma);
    else {
        while (fillActual != nullptr) {
            sumes_camins_aux(fillActual, suma+fillActual->info, v);
            fillActual = fillActual->seggerm;
        }
    }
}