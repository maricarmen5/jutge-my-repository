#include <iostream>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class dicc {

public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Les tres grans: Constructora per còpia, destructora, operador d’assignació
    dicc(const dicc &d);
    ~dicc();
    dicc& operator=(const dicc &d);

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Elimina la clau k del diccionari. Si no hi era, no fa res.
    void elimina(const Clau &k);

    // Consulta si la clau k està en el diccionari.
    bool consulta(const Clau &k) const;

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Impressió per cout de claus del diccionari en ordre ascendent, separades per
    // un espai, començant per ’[’ i acabant per ’]’, en dues versions:
    // Imprimeix totes les claus
    void print() const;
    // Imprimeix les claus entre k1 i k2 ambdós incloses. Pre: k1 <= k2
    void print_interval(const Clau &k1, const Clau &k2) const;

    // Retorna la clau més petita i la més gran respectivament.
    // Pre: El diccionari no està buit
    Clau min() const;
    Clau max() const;

    // Retorna la clau de la posició i-èssima (comptant-les en ordre ascendent).
    // Pre: El diccionari no està buit. 1 <= i <= quants()
    Clau iessim(nat i) const;

private:
// Aquí van els atributs i mètodes privats
    struct node {
        node* fesq;
        node* fdre;
        Clau _k;
    };

    node* _arrel;
    nat _mida;

    bool _eliminar_fesq; // per alternar a l'hora d'eliminar un node i que quedi el més balancejat possible

    node* copia(node* arrel);
    void esborra(node* arrel);
    node* punter_corresponent(node* n, const Clau &k) const;
    node* ajunta(node* fe, node* fd);
    node* deslliga_max_min(node* arrel);
    void print_aux(node* arrel, bool primer) const;
    void print_interval_aux(node* arrel, bool primer, const Clau &k1, const Clau &k2) const;
    Clau iessim_aux(node* arrel, nat& i, nat& index_actual) const;
};

// Aquí va la implementació dels mètodes públics i privats
template <typename Clau>
dicc<Clau>::dicc() {
    _arrel = nullptr;
    _mida = 0;
    _eliminar_fesq = true;
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::copia(node* arrel) {
    node* nou = nullptr;

    if (arrel != nullptr) {
        nou = new node;
        nou->_k = arrel->_k;
        nou->fesq = copia(arrel->fesq);
        nou->fdre = copia(arrel->fdre);
    }

    return nou;
}

template <typename Clau>
dicc<Clau>::dicc(const dicc &d) {
    _arrel = copia(d._arrel);
}

template <typename Clau>
void dicc<Clau>::esborra(node* arrel) {
    if (arrel != nullptr) {
        esborra(arrel->fesq);
        esborra(arrel->fdre);
        delete arrel;
    }
}

template <typename Clau>
dicc<Clau>::~dicc() {
    esborra(_arrel);
}

template <typename Clau>
dicc<Clau>& dicc<Clau>::operator=(const dicc &d) {
    if (this != &d) {
        node* aux = copia(d._arrel);
        _arrel = aux;
    }

    return *this;
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::punter_corresponent(node* n, const Clau &k) const {
    if (n != nullptr and n->_k != k) {
        if (k < n->_k) n = punter_corresponent(n->fesq, k);
        else n = punter_corresponent(n->fdre, k);
    }

    return n;
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
    node* nou = punter_corresponent(_arrel, k);
    if (nou == nullptr) {
        nou = new node;
        nou->_k = k;
        nou->fesq = nullptr;
        nou->fdre = nullptr;
        ++_mida;
    }
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::deslliga_max_min(node* arrel) {
    node* arrelOriginal = arrel;
    node* pare = nullptr;

    if (_eliminar_fesq) {
        while (arrel->fdre != nullptr) {
            pare = arrel;
            arrel = arrel->fdre;
        }
        if (pare != nullptr) {
            pare->fdre = arrel->fesq;
            arrel->fesq = arrelOriginal;
        }
    } else {
        while (arrel->fesq != nullptr) {
            pare = arrel;
            arrel = arrel->fesq;
        }
        if (pare != nullptr) {
            pare->fesq = arrel->fdre;
            arrel->fdre = arrelOriginal;
        }
    }

    return arrel;
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::ajunta(node* fe, node* fd) {
    node* sustitut = fe;
    if (fe == nullptr) sustitut = fd;
    else if (fd != nullptr) { // el node a eliminar té dos fills
        sustitut = deslliga_max_min(sustitut);
        if (_eliminar_fesq) sustitut->fdre = fd;
        else sustitut->fesq = fe;
        _eliminar_fesq = not _eliminar_fesq;
    }

    return sustitut;
}

template <typename Clau>
void dicc<Clau>::elimina(const Clau &k) {
    node* vell = punter_corresponent(_arrel, k);
    if (vell != nullptr) {
        node* aux = vell;
        vell = ajunta(vell->fesq, vell->fdre);
        delete aux;
        --_mida;
    }
}

template <typename Clau>
bool dicc<Clau>::consulta(const Clau &k) const {
    bool trobat = false;

    node* n = punter_corresponent(_arrel, k);
    if (n != nullptr) trobat = true;

    return trobat;
}

template <typename Clau>
nat dicc<Clau>::quants() const {
    return _mida;
}

template <typename Clau>
void dicc<Clau>::print_aux(node* arrel, bool primer) const {
    if (arrel != nullptr) {
        print_aux(arrel->fesq, primer);

        if (primer) {
            cout << '[' << arrel->_k;
            primer = false;
        }
        else cout << ' ' << arrel->_k;

        print_aux(arrel->fdre, primer);
    }
}

template <typename Clau>
void dicc<Clau>::print() const {
    print_aux(_arrel, true);
    cout << ']' << endl;
}

template <typename Clau>
void dicc<Clau>::print_interval_aux(node* arrel, bool primer, const Clau &k1, const Clau &k2) const {
    if (arrel != nullptr) {
        Clau k = arrel->_k;

        if (k1 < k) print_aux(arrel->fesq, primer);

        if (k1 <= k and k <= k2) {
            if (primer) {
                cout << '[' << arrel->_k;
                primer = false;
            }
            else cout << ' ' << k;
        }

        if (k < k2) print_aux(arrel->fdre, primer);
    }
}

template <typename Clau>
void dicc<Clau>::print_interval(const Clau &k1, const Clau &k2) const {
    print_interval_aux(_arrel, true, k1, k2);
    cout << ']' << endl;
}

template <typename Clau>
Clau dicc<Clau>::min() const {
    node* actual = _arrel;
    while (actual->fesq != nullptr) actual = actual->fesq;
    return actual->_k;
}

template <typename Clau>
Clau dicc<Clau>::max() const {
    node* actual = _arrel;
    while (actual->fdre != nullptr) actual = actual->fdre;
    return actual->_k;
}

template <typename Clau>
Clau dicc<Clau>::iessim_aux(node* arrel, nat& i, nat& index_actual) const {
    Clau element_i;

    if (i == index_actual) element_i = arrel->_k;
    else {
        ++index_actual;
        if (arrel->fesq != nullptr) element_i = iessim_aux(arrel->fesq, i, index_actual);
        if (arrel->fdre != nullptr and index_actual < i) element_i = iessim_aux(arrel->fesq, i, index_actual);
    }

    return element_i;
}

template <typename Clau>
Clau dicc<Clau>::iessim(nat i) const {
    nat index_actual = 1;
    Clau element_i = iessim_aux(_arrel, i, index_actual);
    return element_i;
}