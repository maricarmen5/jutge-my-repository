#include <sstream>
using namespace std;
#include "X94927.hpp"
template <typename Clau>
dicc<Clau>::dicc() : _arrel(NULL) {}

template <typename Clau>
dicc<Clau>::~dicc() {
  esborra_nodes(_arrel);
}

template <typename Clau>
void dicc<Clau>::insereix(const Clau &k) {
  _arrel = insereix_bst(_arrel, k);
}

template <typename Clau>
void dicc<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
dicc<Clau>::node::node (const Clau &k, node* esq, node* dret) :
	_k(k), _esq(esq), _dret(dret) {
}

template <typename Clau>
typename dicc<Clau>::node* dicc<Clau>::insereix_bst(node *n, const Clau &k) {
  if (n == NULL) {
    return new node(k);
  }
  else {
    if (k < n->_k) {
      n->_esq = insereix_bst(n->_esq, k);
    }
    else if (k > n->_k) {
      n->_dret = insereix_bst(n->_dret, k);
    }
    return n;
  }
}


int main() {
  string linea;
  int n;

  // Obtenim d1
  dicc<int> d1;
  getline(cin, linea);
  istringstream ss1(linea);
  while (ss1 >> n) {
    d1.insereix(n);
  }

  // Obtenim d2
  dicc<int> d2;
  getline(cin, linea);
  istringstream ss2(linea);
  while (ss2 >> n) {
    d2.insereix(n);
  }

  vector<int> vr = d1.interseccio(d2);

  for (nat i = 0; i < vr.size(); i++) {
    cout << vr[i] << " ";
  }
  return 0;
}
