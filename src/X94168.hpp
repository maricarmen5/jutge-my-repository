#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
// Graf dirigit i no etiquetat.
// Les arestes es guarden en una matriu d’adjacència.
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
vector<vector<bool> > a; // Matriu d’adjacència

// Aquí va l’especificació dels mètodes privats addicionals
nat dfs(nat v, vector<vector<bool> >& visitades) const;
};

// Aquí va la implementació del mètode públic quantes_arestes_es_visiten i privats addicionals

/* Cost temporal: O(n³) en el pitjor cas, ja que per a cada vèrtex (n iteracions) es crida a la funció dfs, O(n * n²) = O(n³). */
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
 * Post: Retorna el nombre d’arestes diferents que es poden visitar 
 *       des del vèrtex v, marcant les arestes visitades a la matriu visitades.
 * Cost temporal: O(n²) en el pitjor cas, ja que es recorren com a màxim 
 *                totes les arestes del graf (n² per una matriu d’adjacència).
 */
nat graf::dfs(nat v, vector<vector<bool> >& visitades) const {
    nat quants = 0;

    for (nat i = 0; i < n; ++i) {
        if (a[v][i] and (not visitades[v][i]) and v != i) {
            visitades[v][i] = true; 
            quants += 1 + dfs(i, visitades);
        }
    }

    return quants;
}