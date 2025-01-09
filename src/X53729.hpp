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

    vector<nat> quants_succ_succ() const;
    // Pre: Cert
    // Post: Retorna quants successors diferents tenen els successors de cada vèrtex
    // del graf

private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<nat> > a; // Vectors amb els successors de cada vèrtex

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode públic quants_succ_succ i privats addicionals

/**
 * Cst temporal: O(n³) en el pitjor cas, ja que hi ha tres nivells de bucles i en grafs densos 
 * (amb moltes arestes) el nombre de successors de segon nivell pot ser proporcional a n.
 */
vector<nat> graf::quants_succ_succ() const {
    vector<nat> quants(n, 0);
    
    for (nat vert = 0; vert < n; ++vert) {
        vector<bool> successorsSucc(n, false);

        for (nat succ = 0; succ < a[vert].size(); ++succ) {
            nat succSucc = a[vert][succ];
            for (nat i = 0; i < a[succSucc].size(); ++i) {
                if (not successorsSucc[a[succSucc][i]]) successorsSucc[a[succSucc][i]] = true;
            }
        }

        for (nat i = 0; i < n; ++i) {
            if (successorsSucc[i]) ++quants[vert];
        }
    }

    return quants;
}