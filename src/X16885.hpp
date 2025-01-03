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

    vector<nat> quants_succ_succ() const;
    // Pre: Cert
    // Post: Retorna quants successors diferents tenen els successors de cada vèrtex
    // del graf

private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<bool> > a; // Matriu d’adjacència

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals

/*
PRE: Cert.
POST: Retorna un vector on la posició v[i] indica quants successors diferents tenen, 
      en total, els successors del vèrtex i del graf.
COST TEMPORAL: O(n³), on n és el nombre de vèrtexs del graf. Justificació:
               - Per a cada vèrtex, es recorren tots els successors (O(n)).
               - Per a cada successor, es verifica si és successor d'un altre vèrtex (O(n)).
               - Això es fa per tots els vèrtexs (O(n)).
*/
vector<nat> graf::quants_succ_succ() const {
    vector<nat> quants(n, 0);
    
    for (nat vert = 0; vert < n; ++vert) {
        vector<nat> succVert;
        for (nat i = 0; i < n; ++i) {
            if (a[vert][i]) succVert.push_back(i);
        }

        for (nat i = 0; i < n; ++i) {
            nat pred = 0;
            while (pred < succVert.size() and (not a[succVert[pred]][i])) ++pred;
            if  (pred < succVert.size() and a[succVert[pred]][i]) ++quants[vert];
        }
    }

    return quants;
}