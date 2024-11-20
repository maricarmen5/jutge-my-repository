#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {
public:
    dicc() : _arrel(NULL) {};
    // Pre: Cert
    // Post: El resultat és un dicc sense cap element

    ~dicc();
    // Pre: Cert
    // Post: El dicc ha estat destruït

    pair<Clau, char> insereix(const Clau &k);
    // Pre: Cert
    // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna la clau dels nodes
    // visitats a on hi ha el desequilibri més proper a les fulles i un caràcter amb el seu
    // tipus de desequilibri: ’E’: Esquerre, ’D’: Dret, ’ ’: No s’ha trobat cap desequilibri

private:
    struct node {
    Clau _k;      // Clau
    node* _esq;   // fill esquerre
    node* _dret;  // fill dret
    nat _h;       // Altura del subarbre
    };
    node *_arrel;

    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals
    void insereix_aux(node*& arrel, const Clau &k, pair<Clau, char>& desequilibri);
};

// Aquí va la implementació dels mètodes públics i privats
// n = nodes de l'arbre

// cost temporal[pitjor cas] = O(n), cost temporal[cas mig] = O(log(n))
template <typename Clau>
pair<Clau, char> dicc<Clau>::insereix(const Clau &k) {
    pair<Clau, char> desequilibri;
    desequilibri.second = ' ';
    insereix_aux(_arrel, k, desequilibri);
    return desequilibri;
}

// cost temporal[pitjor cas] = O(n), cost temporal[cas mig] = O(log(n))
template <typename Clau>
void dicc<Clau>::insereix_aux(node*& arrel, const Clau &k, pair<Clau, char>& desequilibri) {
    if (arrel == nullptr) {
        arrel = new node;
        arrel->_k = k;
        arrel->_h = 1;
        arrel->_esq = nullptr;
        arrel->_dret = nullptr;
    } else {
        if (k < arrel->_k) insereix_aux(arrel->_esq, k, desequilibri);
        else if (arrel->_k < k) insereix_aux(arrel->_dret, k, desequilibri);

        nat alturaEsq = 0;
        if (arrel->_esq != nullptr) alturaEsq = arrel->_esq->_h;
        nat alturaDre = 0;
        if (arrel->_dret != nullptr) alturaDre = arrel->_dret->_h;

        arrel->_h = max(alturaEsq, alturaDre) + 1;
        int factorEquilibri = (int)alturaEsq-(int)alturaDre;

        if (1 < abs(factorEquilibri) and desequilibri.second == ' ') {
            desequilibri.first = arrel->_k;
            if (0 < factorEquilibri) desequilibri.second = 'E';
            else desequilibri.second = 'D';
        }
    }
}