#include <iostream>
#include <vector>
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

    vector<nat> freq_longituds() const;
    // Pre: True
    // Post: Retorna un vector amb les freqüències de les longituds de les claus.
    // La mida del vector és igual a la longitud de la clau més llarga més un. 

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
    void freq_longituds_aux(node* arrel, vector<nat>& frequencies, unsigned int nivell) const;
};

// Aquí va la implementació del mètode públic freq_longituds i privats addicionals
vector<nat> dicc::freq_longituds() const {
    vector<nat> frequencies;
    freq_longituds_aux(_arrel, frequencies, 0);
    return frequencies;
}

// Pre: arrel apunta a un node d'un TST
//      frequencies és un vector que conté les freqüències de longituds fins al nivell actual del TST
//      nivell és la profunditat del node actual en el recorregut de l'arbre
// Post: frequencies s'actualitza, a cada posició i conté el nombre de claus del TST amb longitud i
// Cost: O(n), n = nodes del TST
void dicc::freq_longituds_aux(node* arrel, vector<nat>& frequencies, unsigned int nivell) const {
    if (arrel != nullptr) {
        if (frequencies.size() < nivell+1) frequencies.push_back(0);

        if (arrel->_c == '#') ++frequencies[nivell];
        else freq_longituds_aux(arrel->_cen, frequencies, nivell+1);

        freq_longituds_aux(arrel->_esq, frequencies, nivell);
        freq_longituds_aux(arrel->_dre, frequencies, nivell);
    }
}