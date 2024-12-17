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
    char _c;   // Símbol posició i-èssima de la clau
    node* _pf; // Primer fill, apunta a símbols de la següent posició
    node* _sg; // Següent germà, apunta a símbols de la mateixa posició
    node(const char &c, node* pf = NULL, node* sg = NULL);
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

// Pre: arrel apunta a un node de l'arbre
//      frequencies contéles freqüències de longituds fins al nivell actual de l'arbre
//      nivell és la profunditat del node actual
// Post: s'actualitza frequencies, cada posició i conté el nombre de claus del TST amb longitud i
// Cost: O(n), n = nodes de l'arbre
void dicc::freq_longituds_aux(node* arrel, vector<nat>& frequencies, unsigned int nivell) const {
    node* actual = arrel;
    if (actual != nullptr and frequencies.size() < nivell+1) frequencies.push_back(0);

    while (actual != nullptr) {
        if (actual->_c == '#') ++frequencies[nivell]; 
        else freq_longituds_aux(actual->_pf, frequencies, nivell+1);

        actual = actual->_sg;
    }
}