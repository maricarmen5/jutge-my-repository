#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {
// Diccionari implementat en un BST on les claus poden estar repetides.

public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Imprimeix el contingut del diccionari: Nombre d’elements i
    // totes les claus de més petita a més gran separades per un espai
    void print() const;

    void insereix(const Clau &k);
    // Pre: Cert
    // Post: Insereix la clau k en el diccionari.

    nat quantes(const Clau &k) const;
    // Pre: Cert
    // Post: Retorna el nombre de claus iguals a k

private:
    struct node {
    Clau _k;      // Clau
    node* _esq;   // fill esquerre
    node* _dret;  // fill dret
    };
    node *_arrel;
    nat _n;       // Nombre d’elements del diccionari

    // Elimina els nodes del subarbre apuntat per p
    static void esborra_nodes(node* p);
    // Imprimeix ordenades les claus del subarbre apuntat per p
    static void print(node* p);

    // Aquí va l’especificació dels mètodes privats addicionals
    node* insereix_aux(node* arrel, const Clau &k);
    nat quantes_aux(node* arrel, const Clau &k) const;
};

// Aquí va la implementació dels mètodes públics i dels mètodes privats addicionals

template <typename Clau>
nat dicc<Clau>::quantes(const Clau &k) const {
    nat copiesK = quantes_aux(_arrel, k);
    return copiesK;
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
    _arrel = insereix_aux(_arrel, k);
}

// Pre: `arrel` és la referència a la subarrel d'un BST. `k` és la clau a inserir.
// Post: Insereix la clau `k` al BST. Retorna el punter a l'arrel actualitzada del subarbre.
// Cost temporal: O(h), on h és l'altura del subarbre amb arrel `arrel`.
//                En un BST equilibrat, aquest cost és O(log n), on n és el nombre de nodes de l'arbre.
//                En el pitjor cas (BST completament desequilibrat), el cost és O(n).
template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_aux(node* arrel, const Clau &k) {
    if (arrel == nullptr) {
        arrel = new node;
        arrel->_k = k;
        arrel->_dret = nullptr;
        arrel->_esq = nullptr;
        ++_n;
    } 
    else if (k <= arrel->_k) arrel->_esq = insereix_aux(arrel->_esq, k);
    else if (arrel->_k < k) arrel->_dret = insereix_aux(arrel->_dret, k);

    return arrel;
}

// Pre: `arrel` és la referència a la subarrel d'un BST. `k` és la clau a comptar.
// Post: Retorna el nombre d'elements del BST iguals a `k` en el subarbre amb arrel `arrel`.
// Cost temporal: O(h), on h és l'altura del subarbre amb arrel `arrel`.
//                En un BST equilibrat, aquest cost és O(log n), on n és el nombre de nodes de l'arbre.
//                En el pitjor cas (BST completament desequilibrat), el cost és O(n).
template <typename Clau>
nat dicc<Clau>::quantes_aux(node* arrel, const Clau &k) const {
    nat copiesK = 0;

    if (arrel != nullptr) {
        if (arrel->_k == k) copiesK = 1 + quantes_aux(arrel->_esq, k);
        else if (k < arrel->_k) copiesK = quantes_aux(arrel->_esq, k);
        else if (arrel->_k < k) copiesK = quantes_aux(arrel->_dret, k);
    }

    return copiesK;
}
