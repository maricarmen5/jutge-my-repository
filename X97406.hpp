#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
public:
    dicc();  // Constructora per defecte. Crea un diccionari buit.

    ~dicc(); // Destructora

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const string &k);

    nat quantes_comencen(string inicials) const;
    // Pre: inicials no conté el char ’#’
    // Post: Retorna el nº de claus que comencen per algun dels caràcters que conté inicials

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
    nat quantes_comencen_aux(node* arrel, string& inicials, bool inicial) const;
    bool es_troba_a_inicials(node* arrel, string& inicials) const;
};

// Aquí va la implementació del mètode públic quantes_comencen i privats addicionals
nat dicc::quantes_comencen(string inicials) const {
    nat quantes = quantes_comencen_aux(_arrel, inicials, true);
    return quantes;
}

// Pre: `arrel` apunta al node actual del trie, o és `nullptr`. 
//      `inicials` és una cadena no buida que no conté el caràcter `'#'`.
//      `inicial` indica si estem tractant el primer nivell del trie (true si és el primer nivell).
// Post: Retorna el nombre de claus que comencen per algun dels caràcters de `inicials`.
// Cost temporal: O(n · m), on n és el nombre de nodes del trie i m és la longitud de `inicials`.
nat dicc::quantes_comencen_aux(node* arrel, string& inicials, bool inicial) const {
    nat quantes = 0;

    if (arrel != nullptr) {
        if ((inicial and es_troba_a_inicials(arrel, inicials)) or  
        ((not inicial) and arrel->_c != '#')) {
            quantes = quantes_comencen_aux(arrel->_cen, inicials, false);
        }
        else if ((not inicial) and arrel->_c == '#') quantes = 1;

        quantes += quantes_comencen_aux(arrel->_esq, inicials, inicial);
        quantes += quantes_comencen_aux(arrel->_dre, inicials, inicial);
    }

    return quantes;
}

// Pre: `arrel` apunta a un node del trie, o és `nullptr`.
//      `inicials` és una cadena no buida que no conté el caràcter `'#'`.
// Post: Retorna `true` si el símbol del node actual (`arrel->_c`) 
//       es troba dins de la cadena `inicials`. En cas contrari, retorna `false`.
// Cost temporal: O(m), on m és la longitud de la cadena `inicials`.
bool dicc::es_troba_a_inicials(node* arrel, string& inicials) const {
    bool trobat = false;
    unsigned int i = 0;
    while ((not trobat) and i < inicials.size()) {
        if (arrel->_c == inicials[i]) trobat = true;
        ++i;
    }
    return trobat;
}
