#include <cstdlib>
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
template <typename T>
void heap<T>::elim_min() {
    node* min = _arrel;
    node* ult = nullptr;
    node* pare_ult = nullptr;
    ultim(ult, pare_ult);

    if (ult == min) _arrel = nullptr;
    else {
        _arrel = ult;
        _arrel->pare = nullptr;

        if (pare_ult != min) {
            _arrel->fesq = min->fesq;
            _arrel->fdret = min->fdret;

            if (pare_ult->fdret == ult) pare_ult->fdret = nullptr;
            else pare_ult->fesq = nullptr;

            enfonsar(_arrel);
        }
    }

    delete min;
}

template <typename T>
void heap<T>::enfonsar(node* arrel) {
    node* pare = arrel->pare;
    char tipusArrel = 'X'; // X -> _arrel, E -> pare->fesq = arrel, D pare->fdret = arrel;
    if (pare != nullptr) {
        if (pare->fesq == arrel) tipusArrel = 'E'
        else tipusArrel = 'D';
    }

    node* fill = arrel->fdret;
    char tipusFill = 'D';
    if (fill == nullptr or arrel->fesq->info < fill->info) {
        fill = arrel->fesq;
        tipusFill = 'E';
    }

    if (fill != nullptr) {
        node* germa = arrel->fesq;
        if (tipusFill == 'D') germa = arrel->fdret;

        arrel->fesq = fill->fesq;
        if (fill->fesq != nullptr) fill->fesq->pare = arrel;
        arrel->fdret = fill->fdret;
        if (fill->fdret != nullptr) fill->fdret->pare = arrel;

        fill->pare = pare;
        if (tipusArrel == 'E') pare->fesq = fill;
        else if (tipusArrel == 'D') pare->fdret = fill;

        if (tipusFill == 'E') {
            fill->fesq = arrel;
            fill->fdret = germa;  
        } else {
            fill->fdret = arrel;
            fill->fesq = germa;
        }
        if (germa != nullptr) germa->pare = fill;
        arrel->pare = fill;

        enfonsar(arrel);
    }
}