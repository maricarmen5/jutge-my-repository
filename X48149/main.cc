#include "X48149.hpp" 
template <typename Clau>
bst<Clau>::bst() : _arrel(NULL) {}

template <typename Clau>
void bst<Clau>::esborra_nodes(node* m) {
  if (m != NULL) {
    esborra_nodes(m->_esq);
    esborra_nodes(m->_dret);
    delete m;
  }
}

template <typename Clau>
bst<Clau>::~bst() {
  esborra_nodes(_arrel);
}

template <typename T>
void ordena(vector<T>& v);

template <typename T>
void mostra(vector<T> v) {
  for (nat i=0; i < v.size(); ++i) {
    cout << v[i] << ' ';
  }
  cout << endl;
}

int main() {
  nat n;
  while (cin >> n) {
    vector<double> v(n);
    for (nat i=0; i < n; ++i) {
      cin >> v[i];
    }

    ordena<double>(v);

    mostra<double>(v);
  }
  return 0;
}
