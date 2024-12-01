#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
// Taula de dispersió sinònims encadenats indirectes
// Les llistes de sinònims estan ordenades per clau
public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Impressió per cout de totes les claus del diccionari segons l’ordre
    // en que estan a cadascuna de les llistes encadenades indirectes
    void print() const;

    // Pre: Cert
    // Post: Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const int &k);

    // Pre: El diccionari res està buit
    // Post: Omple res amb la intersecció entre el p.i. i d2
    void interseccio(const dicc &d2, dicc &res) const;

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

// Aquí va la implementació dels mètodes públics insereix, interseccio i
// dels mètodes privats addicionals

// Pre: Cert
// Post: Insereix la clau `k` al diccionari si no hi és. Si ja existeix, no fa res.
// Cost temporal: O(1) en el cas esperat, assumint una bona funció de dispersió i que 
//                les llistes de col·lisions tenen longitud curta (O(α), on α = n / M és 
//                el factor de càrrega).
//                En el pitjor cas (totes les claus a la mateixa llista): O(n), amb n el 
//                nombre d'elements.
void dicc::insereix(const int &k) {
    long i = h(k);
    i = i%_M;

    node_hash* actual = _taula[i];
    node_hash* darrer = nullptr;
    while (actual != nullptr and actual->_k < k) {
        darrer = actual;
        actual = actual->_seg;
    }

    if (actual == nullptr or actual->_k != k) {
        node_hash* nou = new node_hash;
        nou->_k = k;
        nou->_seg = nullptr;

        if (darrer == nullptr) _taula[i] = nou;
        else darrer->_seg = nou;
        if (actual != nullptr) nou->_seg = actual;
        ++_quants;
    }
}

// Pre: El diccionari `res` està buit.
// Post: Omple `res` amb la intersecció dels elements del p.i. i `d2`.
// Cost temporal: O(M + min(n1, n2)), on M és la mida de la taula hash, i 
//                n1 i n2 són el nombre d’elements del p.i. i `d2`, respectivament.
void dicc::interseccio(const dicc &d2, dicc &res) const {
    for (nat i = 0; i < _M; ++i) {
        node_hash* p1 = _taula[i];
        node_hash* p2 = d2._taula[i];

        while (p1 != nullptr and p2 != nullptr) {
            if (p1->_k < p2->_k) p1 = p1->_seg;
            else if (p2->_k < p1->_k) p2 = p2->_seg;
            else {
                res.insereix(p1->_k);
                p1 = p1->_seg;
                p2 = p2->_seg;
            }
        }
    }
}
