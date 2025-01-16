#include <iostream>
using namespace std;
typedef unsigned int nat;


template <typename Clau>
class mfset {
// Partició on les operacions find i merge s’han implementat amb l’estratègia 
// Quick-union. Les claus de la partició es guarden en una taula de dispersió
// amb encadenaments indirectes.

public:
// Constructora per defecte. Crea una partició buida.
mfset();

// Destructora
~mfset();

// Pre: cert
// Post: Insereix la clau k en la partició posant-la en un nou bloc.
// Si ja hi era, no fa res.
void insereix(const Clau &k);

// Pre: cert
// Post: Fusiona els blocs de les claus k1 i k2 amb l’estratègia Quick-union.
// Si k1 o k2 no hi és, no fa res.
void merge(const Clau &k1, const Clau &k2);

// Pre: cert
// Post: Si k hi és, retorna true i la clau del representant del bloc al que pertany k.
// Si k no hi és, retorna false i la clau k.
pair<bool, Clau> find(const Clau &k) const;

private:
struct node {
    Clau _k;           // Clau
    node* _seg;        // Següent sinònim amb el mateix valor de dispersió
    node* _pare_mfset; // Pare de la partició, apunta a nullptr si és el representant del bloc
};
node **_taula; // Taula amb punters a les llistes de sinònims
nat _M;        // Mida de la taula
nat _quants;   // Nº d’elements guardats al diccionari

static long const MULT = 31415926;

// Post: Calcula un valor de dispersió entre 0 i LONG_MAX a partir de k
static long h(Clau k);

// Post: S’han destruït tots els nodes de la llista de sinònims apuntats per m
static void esborra_nodes(node* m);

// Pre: cert
// Post: Si k hi és, retorna un punter al node representant del bloc al que pertany k.
// Si k no hi és, retorna nullptr.
node* find_aux(const Clau &k) const;

// Aquí va l’especificació dels mètodes privats addicionals

};

// Aquí va la implementació del mètode find_aux i dels mètodes privats addicionals

template <typename Clau>
typename mfset<Clau>::node* mfset<Clau>::find_aux(const Clau &k) const {
    long i = h(k)%_M;
    node* repre = _taula[i];
    while (repre != nullptr and repre->_k != k) repre = repre->_seg;

    if (repre != nullptr) { // trobat
        while (repre->_pare_mfset != nullptr) repre = repre->_pare_mfset;
    }

    return repre;
}