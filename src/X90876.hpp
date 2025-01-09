#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
// Graf dirigit i no etiquetat.
// Les arestes es guarden en llistes d’adjacència (vector amb els successors).
public:
    // Constructora per defecte. Crea un graf buit.
    graf();

    // Destructora
    ~graf();

    // Llegeix les dades del graf del canal d’entrada
    void llegeix();

    vector<nat> quantes_arestes_es_visiten() const;
    // Pre: Cert
    // Post: Retorna quantes arestes diferents es poden visitar (hi ha un camí)
    // des de cada vèrtex del graf.

private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes

    struct node_succ {
    nat _succ;        // Vèrtex successor
    node_succ* _seg;  // Següent successor
    };
    vector<node_succ *> a; // Vector amb llistes simplement encadenades
                        // dels successors de cada vèrtex

    // Aquí va l’especificació dels mètodes privats addicionals
    nat dfs(nat v, vector<vector<bool> >& visitades) const;
};

// Aquí va la implementació del mètode públic quantes_arestes_es_visiten i privats addicionals

/**
 * Cost temporal: O(n * m), on n és el nombre de vèrtexs i m el nombre d’arestes del graf.
 * Això és perquè per a cada vèrtex es crida la funció dfs.
 */
vector<nat> graf::quantes_arestes_es_visiten() const {
    vector<nat> quantsVisiten(n, 0); 

    for (nat i = 0; i < n; ++i) {
        vector<vector<bool> > visitades(n, vector<bool>(n, false)); 
        quantsVisiten[i] = dfs(i, visitades); 
    }

    return quantsVisiten;
}

/**
 * Pre: Cert
 * Post: Retorna el nombre d’arestes diferents que es poden visitar des del vèrtex v.
 * Cost temporal: O(m), on m és el nombre d’arestes del graf. Això és perquè per cada aresta
 *                es fa una única visita gràcies a la matriu de visitades, i el recorregut
 *                de la llista d'adjacència es limita a les arestes reals del graf.
 */
nat graf::dfs(nat v, vector<vector<bool> >& visitades) const {
    nat quants = 0;

    node_succ* succAct = a[v];
    while (succAct != nullptr) {
        if (not visitades[v][succAct->_succ]) {
            visitades[v][succAct->_succ] = true;
            quants += 1 + dfs(succAct->_succ, visitades);
        }

        succAct = succAct->_seg;
    }

    return quants;
}