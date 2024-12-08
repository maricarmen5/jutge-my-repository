#include <iostream>
#include <vector>
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

    vector<Clau> interseccio(const dicc<Clau> &d2) const;
    // Pre: True
    // Post: Retorna un vector amb les claus de la intersecció del p.i. amb d2
    // ordenades de menor a major

private:
    struct node {
    Clau _k;      // Clau
    node* _esq;   // fill esquerre
    node* _dret;  // fill dret
    node(const Clau &k, node* esq = NULL, node* dret = NULL);
    };
    node *_arrel;

    static void esborra_nodes(node* m);
    static node* insereix_bst(node *n, const Clau &k);

    // Aquí va l’especificació dels mètodes privats addicionals
    void recorregut_inordre(node* a1, node* a2, vector<Clau>& bst1, vector<Clau>& bst2) const;
};

// Aquí va la implementació dels mètodes públics i privats

/* 
    PRE: True
    POST: Retorna un vector amb les claus de la intersecció 
    del p.i. i d2 ordenades de menor a major.
    COST: O(n1 + n2), on n1 = mida del p.i. i n2 = mida de d2.
*/
template <typename Clau>
vector<Clau> dicc<Clau>::interseccio(const dicc<Clau> &d2) const {
    vector<Clau> bst1;
    vector<Clau> bst2;
    recorregut_inordre(_arrel, d2._arrel, bst1, bst2);

    vector<Clau> intersec;
    nat i = 0;
    nat j = 0;
    while (i < bst1.size() and j < bst2.size()) {
        if (bst1[i] < bst2[j]) ++i;
        else if (bst2[j] < bst1[i]) ++j;
        else {
            intersec.push_back(bst1[i]);
            ++i;
            ++j;
        }
    }

    return intersec;
}

/* 
    PRE: True
    POST: Omple els vectors bst1 i bst2 amb les claus de 
    l'arbre a1 i l'arbre a2, respectivament, seguint un 
    recorregut inordre.
    COST: O(n1 + n2), on n1 és la mida de l'arbre a1 i 
    n2 és la mida de l'arbre a2.
*/
template <typename Clau>
void dicc<Clau>::recorregut_inordre(node* a1, node* a2, vector<Clau>& bst1, vector<Clau>& bst2) const {
    if (a1 == nullptr and a2 != nullptr) {
        recorregut_inordre(a1, a2->_esq, bst1, bst2);
        bst2.push_back(a2->_k);
        recorregut_inordre(a1, a2->_dret, bst1, bst2);
    }
    else if (a1 != nullptr and a2 == nullptr) {
        recorregut_inordre(a1->_esq, a2, bst1, bst2);
        bst1.push_back(a1->_k);
        recorregut_inordre(a1->_dret, a2, bst1, bst2);
    }
    else if (a1 != nullptr and a2 != nullptr) {
        recorregut_inordre(a1->_esq, a2->_esq, bst1, bst2);
        bst1.push_back(a1->_k);
        bst2.push_back(a2->_k);
        recorregut_inordre(a1->_dret, a2->_dret, bst1, bst2);
    }
}