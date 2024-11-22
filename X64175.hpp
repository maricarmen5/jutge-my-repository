#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
// Taula de dispersió sinònims encadenats indirectes
// Les llistes de sinònims estan ordenades per clau
public:
    // Constructora per defecte. Crea un diccionari buit
    // en una taula de dispersió de mida m > 0
    dicc(nat m);

    // Destructora
    ~dicc();

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Impressió per cout de totes les claus del diccionari segons l’ordre
    // en que estan a cadascuna de les llistes encadenades indirectes
    void print() const;

    // Pre: Cert
    // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    // Redimensiona la taula de dispersió amb una mida el doble que 
    // l’anterior més un si el factor de càrrega és superior a 0.8
    void insereix(const int &k);

    // Pre: Cert
    // Post: Retorna el factor de càrrega de la taula de dispersió
    float factor_de_carrega() const;

    // Pre: Cert
    // Post: Redimensiona la taula de dispersió amb una mida el doble que 
    // l’anterior més un (_M => 2*_M+1)
    void redispersio();

private:
    struct node_hash {
    int _k;           // Clau
    node_hash* _seg;
    };
    node_hash **_taula; // Taula amb punters a les llistes de sinònims
    nat _M;             // Mida de la taula
    nat _quants;        // Nº d’elements guardats al diccionari

    static long const MULT = 31415926;

    // Calcula un valor de dispersió entre 0 i LONG_MAX a partir de k
    static long h(int k);

    // Destrueix la llista de nodes apuntats per p
    static void esborra_nodes(node_hash *p);

    // Aquí va l’especificació dels mètodes privats addicionals

};

// Aquí va la implementació dels mètodes públics factor_de_carrega, redispersio i
// dels mètodes privats addicionals

float dicc::factor_de_carrega() const {
    float factorDeCarrega = (float)_quants/(float)_M;
    return factorDeCarrega;
}

void dicc::redispersio() {
    node_hash** exTaula = _taula;
    nat exM = _M;

    _taula = new node_hash*[2*_M+1];
    for (nat i = 0; i <_M; ++i) _taula[i] = nullptr;
    _quants = 0;
    _M = 2*_M+1;

    for (nat i = 0; i < exM; ++i) {
        node_hash* sinonimActual = exTaula[i];
        while (sinonimActual != nullptr) {
            insereix(sinonimActual->_k);
            sinonimActual = sinonimActual->_seg;
        }
    }

    delete exTaula;
}