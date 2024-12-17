#include <cstdlib>
#include <utility> // per utilitzar swap
using namespace std;
typedef unsigned int nat;

template <typename T>
class heap {
public:
    heap(): _arrel(NULL), _nelems(0) {};
    // Pre: Cert
    // Post: El resultat és un heap sense cap element

    heap(heap<T> &he, const T &x, heap<T> &hd);
    // Pre: Cert
    // Post: El resultat és un heap amb x com arrel, he com a fill
    // esquerre i hd com a fill dret. No fa còpia dels heaps he i hd

    heap(const heap<T> &h);
    // Pre: Cert
    // Post: Crea un heap que és una còpia de h

    ~heap();
    // Pre: Cert
    // Post: El heap ha estat destruït

    bool empty() const;
    // Pre: Cert
    // Post: Retorna un booleà indicant si el heap està buit

    T min() const;
    // Pre: El heap no és buit
    // Post: Retorna l’element mínim del heap

    void elim_min();
    // Pre: El heap no és buit
    // Post: S’ha eliminat l’element mínim del heap o qualsevol d’ells si està repetit

private:
    struct node {
    node* fesq;  // Punter al fill esquerre
    node* fdret; // Punter al fill dret
    node* pare;  // Punter al pare
    T info;
    };
    node* _arrel; // Arrel de l’arbre binari del heap
    int _nelems;  // Nombre d’elements del heap

    static node* copia_nodes(node* m, node *n_pare);
    static void esborra_nodes(node* m);

    void ultim(node* &ult, node* &pare_ult) const;
    // Pre: Cert
    // Post: ult conté el punter de l’últim element del heap (NULL si està buit)
    // pare_ult conté el punter del pare de l’últim element del heap (NULL si no en té)

    // Aquí va l’especificació dels mètodes privats addicionals
    void enfonsar(node* arrel);
};

// Aquí va la implementació del mètode elim_min

/* 
* PRE: El heap no és buit.
* POST: S’ha eliminat l’element mínim del heap o qualsevol d’ells si està repetit.
* COST: O(log n), on n és el nombre d’elements del heap. Es localitza l'últim node 
*        en temps O(log n) i després es reorganitza el heap mitjançant enfonsar, que 
*        també té un cost O(log n).
*/
template <typename T>
void heap<T>::elim_min() {
    node* min = _arrel;
    node* ult = nullptr;
    node* pare_ult = nullptr;
    ultim(ult, pare_ult);
    
    if (ult == min) _arrel = nullptr; // _nelems = 1
    else {
        if (pare_ult->fdret == ult) pare_ult->fdret = nullptr;
        else pare_ult->fesq = nullptr;

        _arrel = ult;
        _arrel->pare = nullptr;

        _arrel->fdret = min->fdret;
        if (min->fdret !=  nullptr) min->fdret->pare = _arrel;
        _arrel->fesq = min->fesq;
        if (min->fesq != nullptr) min->fesq->pare = _arrel;

        enfonsar(_arrel);
        while (_arrel->pare != nullptr) _arrel = _arrel->pare;
    }

    delete min;
    --_nelems;
}

/* 
* PRE: L’arrel apunta a un node que compleix la propietat de heap amb els 
*      seus fills, excepte possiblement amb els seus descendents directes.
* POST: L’arrel i tots els seus descendents compleixen la propietat de min-heap.
* COST: O(log n), on n és el nombre d’elements del heap. En el pitjor cas 
*      s'han de fer intercanvis fins a la fulla més profunda del heap.
*/
template <typename T>
void heap<T>::enfonsar(node* arrel) {
    node* pare = arrel->pare;

    node* fill = arrel->fdret;
    node* altreFill = arrel->fesq;
    char tipusFill = 'D';
    if (fill == nullptr or arrel->fesq->info < fill->info) {
        swap(fill, altreFill);
        tipusFill = 'E';
    }

    if (fill != nullptr and fill->info < arrel->info) {
        arrel->fesq = fill->fesq;
        if (fill->fesq != nullptr) fill->fesq->pare = arrel;
        arrel->fdret = fill->fdret;
        if (fill->fdret != nullptr) fill->fdret->pare = arrel;

        if (pare != nullptr and pare->fdret == arrel) pare->fdret = fill;
        else if (pare != nullptr) pare->fesq = fill;
        fill->pare = pare;

        fill->fesq = arrel;
        fill->fdret = altreFill;  
        if (tipusFill == 'D') swap(fill->fdret, fill->fesq);
        if (altreFill != nullptr) altreFill->pare = fill;
        arrel->pare = fill;

        enfonsar(arrel);
    }
}