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

    vector<nat> quants_vertexs_es_visiten() const;
    // Pre: Cert
    // Post: Retorna quants vèrtexs diferents es poden visitar (hi ha un camí)
    // des de cada vèrtex del graf, incloent a ell mateix.

private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<bool> > a; // Matriu d’adjacència

    // Aquí va l’especificació dels mètodes privats addicionals
    // bool hi_ha_cami(nat ini, nat fi, vector<vector<bool>>& visitables, vector<vector<bool>>& comprovats, vector<bool>& camiComprovat) const;
    nat dfs(nat v, vector<bool>& visitats) const;
};

// Aquí va la implementació del mètode públic quants_vertexs_es_visiten i privats addicionals

/* Cost temporal: O(n * (n + m)), on n és el nombre de vèrtexs i m el nombre total d’arestes. */
vector<nat> graf::quants_vertexs_es_visiten() const {
    vector<nat> quantsVisiten(n, 0); 

    for (nat i = 0; i < n; ++i) {
        vector<bool> visitats(n, false); 
        quantsVisiten[i] = dfs(i, visitats);  
    }

    return quantsVisiten;
}

/**
 * Pre: El vèrtex v existeix (0 <= v < n). El vector visitats indica quins vèrtexs ja han estat visitats.
 * Post: Retorna el nombre de vèrtexs accessibles des de v (incloent-hi v) i marca com a visitats tots els vèrtexs accessibles.
 * Cost temporal: O(n + m), on n és el nombre de vèrtexs i m el nombre d’arestes accessibles des de v.
 */
nat graf::dfs(nat v, vector<bool>& visitats) const {
    visitats[v] = true; // Visitem el vèrtex actual
    nat quants = 1;  // Comptem el vèrtex actual

    for (nat i = 0; i < n; ++i) {
        if (a[v][i] and (not visitats[i])) { 
            quants += dfs(i, visitats);  
        }
    }

    return quants;
}