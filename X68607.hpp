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
    node* insereix_aux(node* arrel, const Clau &k);
    node* elimina_aux(node* arrel, const Clau &k);
    node* ajunta(node* fe, node* fd);
    node* deslliga(node* arrel);
    bool consulta_aux(node* arrel, const Clau &k) const; 
    void print_aux(node* arrel, bool& primer) const;
    void print_interval_aux(node* arrel, bool& primer, const Clau &k1, const Clau &k2) const;
    void iessim_aux(node* arrel, nat i, nat& index_actual, Clau& element_i) const;
};

// Aquí va la implementació dels mètodes públics i privats
// n = nodes de l'arbre
// Altura de l'arbre: h = O(n) en el pitjor cas i h = O(log(n)) quan està balancejat

// cost temporal = O(1)
template <typename Clau>
dicc<Clau>::dicc() {
    _arrel = nullptr;
    _mida = 0;
    _eliminar_fesq = true;
}

// cost temporal = O(n)
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

// cost temporal = O(n)
template <typename Clau>
dicc<Clau>::dicc(const dicc &d) {
    _arrel = copia(d._arrel);
}

// cost temporal = O(n)
template <typename Clau>
void dicc<Clau>::esborra(node* arrel) {
    if (arrel != nullptr) {
        esborra(arrel->fesq);
        esborra(arrel->fdre);
        delete arrel;
    }
}

// cost temporal = O(n)
template <typename Clau>
dicc<Clau>::~dicc() {
    esborra(_arrel);
}

// cost temporal = O(n)
template <typename Clau>
dicc<Clau>& dicc<Clau>::operator=(const dicc &d) {
    if (this != &d) {
        node* aux = copia(d._arrel);
        _arrel = aux;
    }

    return *this;
}

// cost temporal en el pitjor cas = O(n) i en el millor (arbre balancejat) = O(log(n))
template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_aux(node* arrel, const Clau &k) {
    if (arrel == nullptr) {
        arrel = new node;
        arrel->_k = k;
        arrel->fesq = nullptr;
        arrel->fdre = nullptr;
        ++_mida;
    }
    else if (k < arrel->_k) arrel->fesq = insereix_aux(arrel->fesq, k);
    else if (arrel->_k < k) arrel->fdre = insereix_aux(arrel->fdre, k);

    return arrel;
}

// cost temporal en el pitjor cas = O(n) i en el millor (arbre balancejat) = O(log(n))
template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
    _arrel = insereix_aux(_arrel, k);
}

// cost temporal = O(h)
template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::deslliga(node* arrel) {
    node* pare = nullptr;

    if (_eliminar_fesq) {
        node* max = arrel;
        while (max->fdre != nullptr) {
            pare = max;
            max = max->fdre;
        }

        if (pare != nullptr) {
            pare->fdre = max->fesq;
            max->fesq = arrel;
        }

        arrel = max;
    } else {
        node* min = arrel;

        while (min->fesq != nullptr) {
            pare = min;
            min = min->fesq;
        }
        if (pare != nullptr) {
            pare->fesq = min->fdre;
            min->fdre = arrel;
        }

        arrel = min;
    }

    return arrel;
}

// cost temporal = O(h)
template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::ajunta(node* fe, node* fd) {
    node* sustitut = fd;

    if (fd == nullptr) sustitut = fe;
    else if (fe != nullptr) { // el node a eliminar té dos fills
        if (_eliminar_fesq) {
            sustitut = deslliga(fe);
            sustitut->fdre = fd;
        } else {
            sustitut = deslliga(fd);
            sustitut->fesq = fe;
        }

        _eliminar_fesq = not _eliminar_fesq;
    }

    return sustitut;
}

// cost temporal = O(h)
template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::elimina_aux(node* arrel, const Clau &k) {
    node* vell = arrel;

    if (arrel != nullptr) {
        if (k < arrel->_k) arrel->fesq = elimina_aux(arrel->fesq, k);
        else if (arrel->_k < k) arrel->fdre = elimina_aux(arrel->fdre, k);
        else {
            arrel = ajunta(arrel->fesq, arrel->fdre);
            delete vell;
            --_mida;
        }
    }

    return arrel;
}

// cost temporal = O(h)
template <typename Clau>
void dicc<Clau>::elimina(const Clau &k) {
    _arrel = elimina_aux(_arrel, k);
}

// cost temporal = O(h)
template <typename Clau>
bool dicc<Clau>::consulta_aux(node* arrel, const Clau &k) const {
    bool trobat = false;

    if (arrel != nullptr) {
        if (arrel->_k == k) trobat = true;
        else if (k < arrel->_k) trobat = consulta_aux(arrel->fesq, k);
        else if (arrel->_k < k) trobat = consulta_aux(arrel->fdre, k);
    }

    return trobat;
}

// cost temporal = O(h)
template <typename Clau>
bool dicc<Clau>::consulta(const Clau &k) const {
    bool trobat = consulta_aux(_arrel, k);
    return trobat;
}

// cost temporal = O(1)
template <typename Clau>
nat dicc<Clau>::quants() const {
    return _mida;
}

// cost temporal = O(n)
template <typename Clau>
void dicc<Clau>::print_aux(node* arrel, bool& primer) const {
    if (arrel != nullptr) {
        print_aux(arrel->fesq, primer);

        if (primer) primer = false;
        else cout << ' ';
        cout << arrel->_k;

        print_aux(arrel->fdre, primer);
    }
}

// cost temporal = O(n)
template <typename Clau>
void dicc<Clau>::print() const {
    cout << '[';
    bool primer = true;
    print_aux(_arrel, primer);
    cout << ']';
}

// cost temporal = O(m+h), m = nodes de [k1,k2]
template <typename Clau>
void dicc<Clau>::print_interval_aux(node* arrel, bool& primer, const Clau &k1, const Clau &k2) const {
    if (arrel != nullptr) {
        if (k1 < arrel->_k) print_interval_aux(arrel->fesq, primer, k1, k2);

        if (k1 <= arrel->_k and arrel->_k <= k2) {
            if (primer) primer = false;
            else cout << ' ';
            cout << arrel->_k;
        }

        if (arrel->_k < k2) print_interval_aux(arrel->fdre, primer, k1, k2);
    }
}

// cost temporal = O(m+h), m = nodes de [k1,k2]
template <typename Clau>
void dicc<Clau>::print_interval(const Clau &k1, const Clau &k2) const {
    cout << '[';
    bool primer = true;
    print_interval_aux(_arrel, primer, k1, k2);
    cout << ']';
}

// cost temporal = O(h)
template <typename Clau>
Clau dicc<Clau>::min() const {
    node* actual = _arrel;
    while (actual->fesq != nullptr) actual = actual->fesq;
    return actual->_k;
}

// cost temporal = O(h)
template <typename Clau>
Clau dicc<Clau>::max() const {
    node* actual = _arrel;
    while (actual->fdre != nullptr) actual = actual->fdre;
    return actual->_k;
}

// cost temporal = O(h+i)
template <typename Clau>
void dicc<Clau>::iessim_aux(node* arrel, nat i, nat& index_actual, Clau& element_i) const {
    if (arrel->fesq != nullptr) iessim_aux(arrel->fesq, i, index_actual, element_i);

    ++index_actual;
    if (index_actual == i) element_i = arrel->_k;

    if (index_actual < i and arrel->fdre != nullptr) iessim_aux(arrel->fdre, i, index_actual, element_i);
}

// cost temporal = O(h+i)
template <typename Clau>
Clau dicc<Clau>::iessim(nat i) const {
    nat index_actual = 0;
    Clau element_i = _arrel->_k;
    iessim_aux(_arrel, i, index_actual, element_i);
    return element_i;
}