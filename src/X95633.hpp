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

    // Retorna un vector amb els successors del vèrtex v
    vector<nat> successors(nat v) const;

    // Retorna un vector amb els predecessors del vèrtex v
    vector<nat> predecessors(nat v) const;

    void insereix(nat orig, nat dest);
    // Pre: orig i dest són menors que el número de vèrtexs
    // Post: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest.
        // Si l’aresta ja existia no fa res.

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

// Aquí va la implementació del mètode públic insereix i privats addicionals

/*
PRE: orig i dest són menors que el nombre de vèrtexs nv.
POST: Insereix una aresta que connecta des del vèrtex orig cap al vèrtex dest. 
      Si l’aresta ja existia, no fa res.
COST TEMPORAL: O(na), on na és el nombre d’arestes sortints del vèrtex orig i entrants al vèrtex dest,
               perquè s’han de recórrer les llistes ordenades de successors i predecessors.
*/
void graf::insereix(nat orig, nat dest) {
    node* succOrigAnt = nullptr;
    node* succOrigAct = prim_succ[orig];
    while (succOrigAct != nullptr and succOrigAct->dest < dest) {
        succOrigAnt = succOrigAct;
        succOrigAct = succOrigAct->seg_succ;
    }

    if (succOrigAct == nullptr or succOrigAct->dest != dest) { // l'aresta no existeix encara
        // actualitzem prim_succ
        node* succNou = new node{orig, dest, succOrigAct, nullptr};
        if (succOrigAnt == nullptr) prim_succ[orig] = succNou;
        else succOrigAnt->seg_succ = succNou;

        // actualitzem prim_pred
        node* predDestAnt = nullptr;
        node* predDestAct = prim_pred[dest];
        while (predDestAct != nullptr and predDestAct->orig < orig) {
            predDestAnt = predDestAct;
            predDestAct = predDestAct->seg_pred;
        }

        node* predNou = new node{orig, dest, nullptr, predDestAct};
        if (predDestAnt == nullptr) prim_pred[dest] = predNou;
        else predDestAnt->seg_pred = predNou;
    }
}