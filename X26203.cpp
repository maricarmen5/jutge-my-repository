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

    // Retorna la enésima clau del arbre.
    // Pre: El diccionari té com a mínim 1 clau.
    Clau n_endevant(int i) const;

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
    void n_endevant_aux(node* arrel, int& index, int final, Clau& v) const;       
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

/* 
   Pre: 'arrel' apunta a un node d'un arbre binari de cerca, 'index' i 'final' són enters inicialitzats.
   Post: Retorna la clau de l'í-èsim node (seguint l'ordre inordre) si existeix, emmagatzemada en 'v'.
   Cost temporal: O(n) en el pitjor cas, on n és el nombre de nodes de l'arbre. L'algorisme recorre l'arbre
                  en profunditat inordre fins arribar a l'element desitjat.
*/
template <typename Clau>
void dicc<Clau>::n_endevant_aux(node* arrel, int& index, int final, Clau& v) const {
  if (arrel != nullptr) {
    n_endevant_aux(arrel->_esq, index, final, v);
    ++index;
    if (index == final) v = arrel->_k;
    else if (index < final) n_endevant_aux(arrel->_dret, index, final, v);
  }
}

/* 
   Pre: El diccionari té com a mínim una clau i 1 ≤ i ≤ nombre de claus.
   Post: Retorna la clau que ocupa la posició i-èssima en l'ordre inordre.
   Cost temporal: O(n) en el pitjor cas, on n és el nombre de nodes de l'arbre. La funció crida a 
                  n_endevant_aux per recórrer l'arbre en inordre fins a trobar la clau desitjada.
*/
template <typename Clau>
Clau dicc<Clau>::n_endevant(int i) const {
  node *n;  
  n = _arrel;
  Clau v;
  int index = 0;
  int final = i;
  n_endevant_aux(n, index, final, v);
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
      if (comanda == "n_endevant") { 
        int i;
        ss2 >> i;       
        cout << "és " << d.n_endevant(i) << endl;
      }
    }
    if (linea == "----------")
      cout << linea << endl;
  }
  return 0;
}

