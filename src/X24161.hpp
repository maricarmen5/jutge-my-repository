#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const string &k);

    nat quantes_interval(string inicial, string final) const;
    // Pre: Les claus inicial i final estan en el diccionari
    // Post: Retorna el nombre de claus que compleixen: inicial <= clau <= final

private:
    struct node {
    char _c;    // Símbol posició i-èssima de la clau
    node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
    node* _cen; // Fill central, apunta a símbols següent posició
    node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
    node(const char &c, node* esq = NULL, node* cen = NULL, node* dre = NULL);
    };
    node* _arrel;

    static void esborra_nodes(node* t);
    static node* insereix(node *t, nat i, const string &k);

    // Aquí va l’especificació dels mètodes privats addicionals
    nat quantes_interval_aux(node* t, string& inicial, string& final, string paraula) const;
};

// Aquí va la implementació del mètode públic quantes_interval i privats addicionals

/* Cost temporal: O(k * n), on k és la longitud mitjana de les claus i n és el nombre total de claus en el diccionari. */
nat dicc::quantes_interval(string inicial, string final) const {
    string paraula = "";
    nat quantes = quantes_interval_aux(_arrel, inicial, final, paraula);
    return quantes;
}

/**
 * Pre: Les claus inicial i final estan en el diccionari i la clau actual és una cadena buida.
 * Post: Retorna el nombre de claus que compleixen la condició: inicial <= clau <= final.
 * 
 * Cost temporal: O(k * n), on k és la longitud mitjana de les claus i n és el nombre total de nodes
 * a recórrer en el diccionari (el nombre de nodes dependrà de la forma de l'arbre, però en el pitjor cas
 * pot ser proporcional a la profunditat de l'arbre, que pot arribar a ser O(n)).
 */
nat dicc::quantes_interval_aux(node* t, string& inicial, string& final, string paraula) const {
    nat quantes = 0;

    if (t != nullptr) {
        if (inicial <= paraula+t->_c) quantes += quantes_interval_aux(t->_esq, inicial, final, paraula);

        if (t->_c != '#') quantes += quantes_interval_aux(t->_cen, inicial, final, paraula+t->_c);
        else if (inicial <= paraula and paraula <= final) quantes += 1;

        if (paraula+t->_c <= final) quantes += quantes_interval_aux(t->_dre, inicial, final, paraula);
    }

    return quantes;
}