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

vector<T> compta_elements_nivells() const;
// PRE: Cert
// POST: Retorna un vector amb el nombre d’elements de cada nivell de l’arbre.

private:
Arbre(): _arrel(nullptr) {};
struct node {
T info;
node* primf;
node* seggerm;
};
node* _arrel;
static node* copia_arbre(node* p);
static void destrueix_arbre(node* p) throw();

// Aquí va l’especificació dels mètodes privats addicionals
void compta_elements_nivells_aux(node* arrel, int nivell, vector<T>& resultat) const;
};

// Aquí va la implementació del mètode compta_elements_nivells i privats addicionals
template <typename T>
vector<T> Arbre<T>::compta_elements_nivells() const {
    vector<T> resultat;
    if (_arrel != nullptr) compta_elements_nivells_aux(_arrel, 1, resultat);
    return resultat;
}

// PRE: arrel no és nullptr
// POST: el vector resultat té el nombre d’elements de cada nivell del que portem d'arbre
template <typename T>  // cost lineal: theta(n)
void Arbre<T>::compta_elements_nivells_aux(node* arrel, int nivell, vector<T>& resultat) const {
    if ((int)resultat.size() < nivell) resultat.push_back(1);
    else ++resultat[nivell-1];

    node* fillActual = arrel->primf;
    while (fillActual != nullptr) {
        compta_elements_nivells_aux(fillActual, nivell+1, resultat);
        fillActual = fillActual->seggerm;
    }
}