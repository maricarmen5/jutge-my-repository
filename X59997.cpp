#include <iostream>
#include <sstream>
using namespace std;
typedef unsigned int nat;


template <typename Clau>
class dicc {

  public:
    // Constructora per defecte. Crea un diccionari buit.
    dicc();

    // Destructora
    ~dicc();

    // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
    void insereix(const Clau &k);

    // Retorna quants elements (claus) té el diccionari.
    nat quants() const;

    // Retorna la enésima clau del arbre comenza desde el final i va 
    // cap endarrera.
    // Pre: El diccionari té com a mínim 1 clau.
    Clau n_endarrera(int i) const;

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
      nat _n;       // Nombre de nodes del subarbre
      node(const Clau &k, node* esq = NULL, node* dret = NULL);
    };
    node *_arrel;

    static void esborra_nodes(node* m);
    static node* insereix_bst(node *n, const Clau &k, bool &ins);

    void n_endarrera_aux(node* arrel, int& index, int final, Clau& v) const;        
};

template <typename Clau>
dicc<Clau>::dicc() : _arrel(NULL) {}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}

template <typename Clau>
dicc<Clau>::node::node (const Clau &k, node* esq, node* dret) :
  _k(k), _esq(esq), _dret(dret), _n(1) {
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
  bool ins = false;
  _arrel = insereix_bst(_arrel, k, ins);
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_bst (node *n, const Clau &k, bool &ins) {
  if (n == NULL) {
    ins = true;
    return new node(k);
  }
  else {
    if (k < n->_k) {
      n->_esq = insereix_bst(n->_esq, k, ins);
    }
    else if (k > n->_k) {
      n->_dret = insereix_bst(n->_dret, k, ins);
    }
    if (ins)
      n->_n++;
    return n;
  }
}

template <typename Clau>
nat dicc<Clau>::quants() const {
  nat n = 0;
  if (_arrel != NULL)
    n = _arrel->_n;
  return n;
}

/* Pre: arrel apunta a un node vàlid; index és inicialitzat amb n; final és la posició buscada. 
   Post: Actualitza v amb la clau en la posició final (ordre descendent). 
   Cost: O(n), on n és el nombre de claus. */
template <typename Clau>
void dicc<Clau>::n_endarrera_aux(node* arrel, int& index, int final, Clau& v) const {
  if (arrel->_dret != nullptr) n_endarrera_aux(arrel->_dret, index, final, v);

  --index;
  if (index == final) v = arrel->_k;

  if (final < index and arrel->_esq != nullptr) n_endarrera_aux(arrel->_esq, index, final, v);
}

/* Pre: El diccionari té almenys una clau i 1 ≤ i ≤ n (nombre de claus). 
   Post: Retorna la clau a la posició i des del final en ordre descendent.
   Cost: O(n), on n és el nombre de claus. */
template <typename Clau>
Clau dicc<Clau>::n_endarrera(int i) const {
  node *n;
  Clau v;
  n = _arrel;
  int final = n->_n-i;
  int index = n->_n;
  n_endarrera_aux(n, index, final, v);
  return v;
}

int main() {
  string linea, comanda;;
  int n;
  while (getline(cin, linea)) {
    dicc<int> d;

    // Obtenim elements 1er diccionari
    istringstream ss1(linea);
    while (ss1 >> n) {
      d.insereix(n);
    }
    cout << d.quants() << endl;    
    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda;      
      if (comanda == "n_endarrera") { 
        int i;
        ss2 >> i;       
        cout << "és " << d.n_endarrera(i) << endl;
      }
    }
    if (linea == "----------")
      cout << linea << endl;
  }
  return 0;
}

