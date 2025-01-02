#include <vector>
using namespace std;
typedef unsigned int nat;
#include <iostream>
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

    bool hi_ha_cami(nat ini, nat fi) const;
    // Pre: ini i fi són vèrtexs del graf (són menors que n)
    // Post: Retorna un booleà indicant si hi ha camí per anar d’ini a fi

private:
    nat n; // Nombre de vèrtexs
    nat m; // Nombre d’arestes
    vector<vector<bool> > a; // Matriu d’adjacència

    // Aquí va l’especificació dels mètodes privats addicionals
    bool hi_ha_cami_aux(nat ini, nat fi, vector<bool>& visitats) const;
};

// Aquí va la implementació del mètode públic hi_ha_cami i privats addicionals

/*
COST TEMPORAL: O(n + m), on n és el nombre de vèrtexs i m el nombre d'arestes, en el pitjor cas.
*/
bool graf::hi_ha_cami(nat ini, nat fi) const {
    vector<bool> visitats(n, false);
    bool cami = hi_ha_cami_aux(ini, fi, visitats);
    return cami;
}

/*
PRE: ini i fi són vèrtexs del graf (ini i fi són menors que n) i visitats és un vector booleà inicialitzat amb false.
POST: Retorna un booleà que indica si existeix un camí del vèrtex ini al vèrtex fi, visitant cada vèrtex com a màxim una vegada.
COST TEMPORAL: O(n + m), on n és el nombre de vèrtexs i m el nombre d'arestes, en el pitjor cas.
*/
bool graf::hi_ha_cami_aux(nat ini, nat fi, vector<bool>& visitats) const {    
    bool cami = false;

    if (ini == fi) cami = true;
    else if (not visitats[ini]) {
        visitats[ini] = true;

        nat i = 0;
        while (i < a.size() and (not cami)) {
            if (a[ini][i]) cami = hi_ha_cami_aux(i, fi, visitats);
            ++i;
        }
    }

    return cami;
}