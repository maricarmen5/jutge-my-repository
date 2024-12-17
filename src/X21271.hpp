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

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Pre: El diccionari no està buit. 1 <= i <= j <= quants()
    // Post: Retorna les claus entre la posició i-èssima i j-èssima
    // (comptant-les en ordre ascendent).
    vector<Clau> ijessim(nat i, nat j) const;

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
    void ijessim_aux(node* arrel, nat& actual, nat inici, nat final, vector<Clau>& v) const;
};


// Aquí va la implementació dels mètodes públics i privats

/* 
   Cost temporal: O(log n + (j - i + 1)) en el cas mig, on n és 
   el nombre total de claus i (j - i + 1) és el nombre de claus 
   retornades.
*/
template <typename Clau>
vector<Clau> dicc<Clau>::ijessim(nat i, nat j) const {
    vector<Clau> v(j-i+1);
    node* arrel = _arrel;
    nat actual = 0;
    nat inici = i;
    nat final = j;
    ijessim_aux(arrel, actual, inici, final, v);
    return v;
}

/* 
   Pre: 'arrel' apunta a un node d'un arbre binari de cerca 
   (pot ser nullptr), 'actual' està inicialitzat, i 'inici' 
   i 'final' compleixen 1 <= inici <= final <= nombre de claus.
   Post: Emmagatzema en el vector 'v' les claus entre les 
   posicions inici i final (seguint l'ordre inordre i comptant 
   des de l'índex 1).
   Cost temporal: O(log n + (j - i + 1)) en el cas mig, on n és
   el nombre total de claus de l'arbre i (j - i + 1) és el 
   nombre de claus a retornar. S'aprofita la propietat de l'arbre 
   binari de cerca per evitar recorreguts innecessaris.
*/
template <typename Clau>
void dicc<Clau>::ijessim_aux(node* arrel, nat& actual, nat inici, nat final, vector<Clau>& v) const {
    if (arrel != nullptr) {
        if (arrel->_esq != nullptr and inici <= arrel->_esq->_n+actual) {
            ijessim_aux(arrel->_esq, actual, inici, final, v);
        } 
        else if (arrel->_esq != nullptr) actual += arrel->_esq->_n; 

        ++actual;
        if (inici <= actual and actual <= final) v[actual-inici] = arrel->_k;

        if (actual <= final) ijessim_aux(arrel->_dret, actual, inici, final, v);
    }
}