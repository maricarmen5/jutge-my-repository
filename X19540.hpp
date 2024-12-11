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

    // Imprimeix els elements del diccionari ordenats de menor a major
    void print() const;

    // Retorna la mida del BST que implementa el diccionari
    nat mida() const;

    // Retorna l’altura del BST que implementa el diccionari
    nat altura() const;

    void diferencia(const dicc<Clau> &d2, dicc<Clau> &dr) const;
    // Pre: El diccionari dr està buit
    // Post: dr conté les claus de la diferència del p.i. amb d2

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
    static void print(node *n);
    static nat mida(node *n);
    static nat altura(node *n);

    // Aquí va l’especificació dels mètodes privats addicionals
    void diferencia_aux(node* arrel, const dicc<Clau> &d2, dicc<Clau> &dr) const;
    bool consulta(node* arrel, const Clau& k) const;
};

// Aquí va la implementació dels mètodes públics i privats

/* 
   Pre: El diccionari actual ('this') i 'd2' són diccionaris vàlids.
        'dr' és un diccionari buit on es guardaran els resultats de la diferència.
   Post: Retorna en 'dr' les claus que són presents en el diccionari actual però no en 'd2'.
   Cost temporal: O(n * log m), on n és el nombre de claus en el diccionari actual i m és el nombre de claus en 'd2',
                  ja que per cada clau de l'arbre es fa una consulta en el diccionari 'd2' (cercant en un arbre binari de cerca).
*/
template <typename Clau>
void dicc<Clau>::diferencia(const dicc<Clau> &d2, dicc<Clau> &dr) const {
    diferencia_aux(_arrel, d2, dr);
}

/* 
   Pre: 'arrel' és un node d'un arbre binari de cerca, 'd2' és un diccionari vàlid, i 'dr' és un diccionari buit.
   Post: Recorre recursivament l'arbre en ordre aleatori per trobar les claus que estan a l'arbre actual 
         però no a 'd2', i les insereix a 'dr'.
   Cost temporal: O(n * log m), on n és el nombre de nodes de l'arbre actual i m és el nombre de claus en 'd2'.
                  El cost depèn del nombre de nodes recorreguts (n) i de la consulta a l'altre diccionari (log m).
                  L'ordenació aleatòria de la recursió no afecta el cost temporal.
*/
template <typename Clau>
void dicc<Clau>::diferencia_aux(node* arrel, const dicc<Clau> &d2, dicc<Clau> &dr) const {
    if (arrel != nullptr) {
        bool iguals = d2.consulta(d2._arrel, arrel->_k);
        if (not iguals) dr.insereix(arrel->_k);
        
        int moneda = rand()%2;
        if (moneda == 0) {
            diferencia_aux(arrel->_esq, d2, dr);
            diferencia_aux(arrel->_dret, d2, dr);
        } else {
            diferencia_aux(arrel->_dret, d2, dr);
            diferencia_aux(arrel->_esq, d2, dr);
        }
    }
}

/* 
   Pre: 'arrel' és un node d'un arbre binari de cerca, i 'k' és una clau a cercar.
   Post: Retorna 'true' si la clau 'k' es troba en l'arbre, 'false' en cas contrari.
   Cost temporal: O(log n), on n és el nombre de nodes de l'arbre. Es fa una recerca binària en l'arbre.
*/
template <typename Clau>
bool dicc<Clau>::consulta(node* arrel, const Clau& k) const {
    bool trobat = false;

    if (arrel != nullptr) {
        if (k == arrel->_k) trobat = true;
        else if (arrel->_k < k) trobat = consulta(arrel->_dret, k);
        else trobat = consulta(arrel->_esq, k);
    }

    return trobat;
}