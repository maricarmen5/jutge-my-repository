#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
  // Graf dirigit i no etiquetat de vèrtexs [0, n-1]
  // Les arestes es guarden en llistes d’adjacència (llistes
  // simplement encadenades amb els successors de cada vèrtex).
  public:
    // Constructora per defecte. Crea un graf buit.
    graf();

    // Destructora
    ~graf();

    // Llegeix les dades del graf del canal d’entrada
    void llegeix();

    vector<bool> hi_ha_cicles() const;
    // Pre: Cert
    // Post: Retorna si hi ha algun cicle des de cada vèrtex del graf.

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
    bool hi_ha_cicle(nat v, vector<bool>& cami, vector<vector<bool>>& visitades) const;
};

// Aquí va la implementació del mètode públic i dels mètodes privats addicionals

/* Cost temporal: O(n*(n+m)) */
vector<bool> graf::hi_ha_cicles() const {
    vector<bool> cicles(n, false);

    for (nat i = 0; i < n; ++i) {
        vector<bool> cami(n, false);
        vector<vector<bool>> visitades(n, vector<bool>(n, false));

        cami[i] = true;
        cicles[i] = hi_ha_cicle(i, cami, visitades);
    }

    return cicles;
}

/**
 * Pre: v natural <= n, cami conté els vèrtexs que formen part del camí acumulat, visitades
 * conté les arestes ja explorades.
 * Post: retorna true si hi ha un cicle des del vèrtex v. Retorna false altrament.
 * Cost temporal: O(n + m).
 */
bool graf::hi_ha_cicle(nat v, vector<bool>& cami, vector<vector<bool>>& visitades) const {
    bool cicle = false;

    node_succ* succ = a[v];
    while ((not cicle) and succ != nullptr and (not visitades[v][succ->_succ])) {
        visitades[v][succ->_succ] = true;

        if (cami[succ->_succ]) cicle = true;
        else {
            cami[succ->_succ] = true;
            cicle = hi_ha_cicle(succ->_succ, cami, visitades);
            if (not cicle) cami[succ->_succ] = false;
        }

        succ = succ->_seg;
    }

    return cicle;
}