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

    vector<Clau> insereix(const Clau &k);
    // Pre: Cert
    // Post: La clau k s’ha inserit en el diccionari si no hi era. Retorna un vector amb 
    // les claus dels nodes visitats on hi ha un desequilibri desprès de la inserció,
    // començant per la més propera a les fulles i acabant per la més propera a l’arrel.

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
    void insereix_aux(node*& arrel, const Clau &k, vector<Clau>& desequilibrats);
};

// Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
vector<Clau> dicc<Clau>::insereix(const Clau &k) {
    vector<Clau> desequilibrats;
    insereix_aux(_arrel, k, desequilibrats);
    return desequilibrats;
}

// Pre: 'arrel' és un punter a un node d’un BST o un punter nul
//      'k' és una clau que volem inserir
//      'desequilibrats' és un vector buit o inicialitzat
// Post: La clau 'k' s'ha inserit al BST si no hi era. 
//       El vector 'desequilibrats' conté les claus dels nodes amb desequilibri després de la inserció, 
//       començant pels més propers a les fulles.
// Cost: O(h), on h és l'alçada de l'arbre. En un BST equilibrat, O(log n); en el pitjor cas, O(n). n = nodes de l'arbre
template <typename Clau>
void dicc<Clau>::insereix_aux(node*& arrel, const Clau &k, vector<Clau>& desequilibrats) {
    if (arrel == nullptr) {
        arrel = new node;
        arrel->_k = k;
        arrel->_h = 1;
        arrel->_esq = nullptr;
        arrel->_dret = nullptr;
    } else {
        if (k < arrel->_k) insereix_aux(arrel->_esq, k, desequilibrats);
        else if (arrel->_k < k) insereix_aux(arrel->_dret, k, desequilibrats);

        nat alturaEsq = 0;
        if (arrel->_esq != nullptr) alturaEsq = arrel->_esq->_h;
        nat alturaDre = 0;
        if (arrel->_dret != nullptr) alturaDre = arrel->_dret->_h;

        arrel->_h = max(alturaEsq, alturaDre) + 1;
        int factorEquilibri = (int)alturaEsq-(int)alturaDre;

        if (1 < abs(factorEquilibri)) desequilibrats.push_back(arrel->_k);
    }
}