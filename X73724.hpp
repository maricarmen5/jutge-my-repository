#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {

public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Pre: La clau k existeix al diccionari i té successor.
    // Post: Retorna la clau successora de la clau k.
    Clau successor(const Clau &k) const;

private:
    struct node {
    Clau _k;      // Clau
    node* _esq;   // fill esquerre
    node* _dret;  // fill dret
    nat _n;       // Nombre de nodes del subarbre
    node(const Clau &k, node* esq = NULL, node* dret = NULL);
    };
    node *_arrel;

    static void esborra_nodes(node* m);
    static node* insereix_bst(node *n, const Clau &k, bool &ins);

    // Aquí va l’especificació dels mètodes privats addicionals
    node* successor_aux(node* arrel, const Clau &k) const;
};

// Aquí va la implementació dels mètodes públics i privats

// Pre: La clau `k` existeix en el diccionari i té un succesor.
// Post: Retorna la clau successora de `k` en el diccionari, o sigui, 
//       la clau més petita que és estrictament major que `k`.
// Cost: O(h), h = altura de l'arbre, si està força equilibrat llavors h = O(log(n)) sinò O(n), n = nodes de l'arbre
template <typename Clau>
Clau dicc<Clau>::successor(const Clau &k) const {
    node* nodeK = _arrel;
    node* possibleNodeS = nullptr;
    while (nodeK->_k != k) {
        if (nodeK->_k < k) { // possibleNodeS ha de ser l'avi, no el pare
            nodeK = nodeK->_dret;
        } else { // k < nodeK->_k
            possibleNodeS = nodeK;
            nodeK = nodeK->_esq;
        }
    }

    node* nodeS = nullptr;
    if (nodeK->_dret == nullptr) nodeS = possibleNodeS; // possibleNodeS != NULL perquè k ha de tenir successor
    else {
        nodeS = nodeK->_dret;
        while (nodeS->_esq != nullptr) nodeS = nodeS->_esq;
    }

    return nodeS->_k;
}
