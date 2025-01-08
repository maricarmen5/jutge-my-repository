#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

class graf {
// Graf dirigit i no etiquetat.
// Les arestes es guarden en multillistes d’adjacència en memòria dinàmica.
public:
    // Constructora per defecte. Crea un graf buit de n vèrtexs.
    graf(nat n);

    // Destructora
    ~graf();

    void insereix(nat orig, nat dest);
    // Pre: orig i dest són més petits que el número de vèrtexs
    // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
    // Si l’aresta ja existia no fa res.

    vector<nat> successors(nat v) const;
    // Pre: v és més petit que el número de vèrtexs
    // Post: Retorna un vector amb els successors del vèrtex v

    vector<nat> predecessors(nat v) const;
    // Pre: v és més petit que el número de vèrtexs
    // Post: Retorna un vector amb els predecessors del vèrtex v

    void elimina(nat orig, nat dest);
    // Pre: orig i dest són més petits que el número de vèrtexs
    // Post: Elimina una aresta que connecta des del vèrtex orig cap al vèrtex dest.
    // Si l’aresta no existia no fa res.

private:
    nat nv; // Nombre de vèrtexs
    struct node {
    nat orig; // Vèrtex origen 
    nat dest; // Vèrtex destí 
    node *seg_succ; // Punter al següent successor
    node *seg_pred; // Punter al següent predecessor
    };
    vector<node *> prim_succ; // Punters al primer successor de cada vèrtex.
                            // La llista de successors està ordenada.
    vector<node *> prim_pred; // Punters al primer predecessor de cada vèrtex.
                            // La llista de predecessors està ordenada.

    // Aquí va l’especificació dels mètodes privats addicionals
};

// Aquí va la implementació del mètode elimina i privats addicionals

/*
PRE: `orig` i `dest` són menors que el nombre de vèrtexs `nv`.
POST: Elimina l’aresta que connecta `orig` amb `dest`, si existeix. 
      Les llistes de successors i predecessors es mantenen ordenades.
COST TEMPORAL: O(na), on `na` és el nombre d’arestes sortints de `orig` més el nombre d’arestes entrants a `dest`.
*/
void graf::elimina(nat orig, nat dest) {
    node* succOrigAct = prim_succ[orig];
    node* succOrigAnt = nullptr;
    while (succOrigAct != nullptr and succOrigAct->dest < dest) {
        succOrigAnt = succOrigAct;
        succOrigAct = succOrigAct->seg_succ;
    }

    if (succOrigAct != nullptr and succOrigAct->dest == dest) { // l'aresta existeix
        if (succOrigAnt == nullptr) prim_succ[orig] = succOrigAct->seg_succ;
        else succOrigAnt->seg_succ = succOrigAct->seg_succ;

        node* predDestAct = prim_pred[dest];
        node* predDestAnt = nullptr;
        while (predDestAct->orig < orig) {
            predDestAnt = predDestAct;
            predDestAct = predDestAct->seg_pred;
        }
        if (predDestAnt == nullptr) prim_pred[dest] = predDestAct->seg_pred;
        else predDestAnt->seg_pred = predDestAct->seg_pred;

        delete predDestAct; // és el mateix node al que apunta succOrigAct
    }
}