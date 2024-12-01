#include <iostream>
#include <stack>
#include "X14777.hpp"
template <typename T>
typename heap<T>::node* heap<T>::copia_nodes(node* m, node *n_pare) {
/* Pre:  Cert */
/* Post: Si m és NULL, el resultat és NULL; sinó,
   el resultat apunta al primer node d'un heap
   de nodes que són còpia del heap apuntat per m.
   El primer node còpia té com a pare n_pare*/
  node* n;
  if (m == NULL) n = NULL;
  else {
    n = new node;
    try {
      n->info = m->info;
      n->fesq = copia_nodes(m->fesq, n);
      n->fdret = copia_nodes(m->fdret, n);
      n->pare = n_pare;
    } catch(...) {
      delete n;
      throw;
    }
  }
  return n;
};

template <typename T>
void heap<T>::esborra_nodes(node* m) {
/* Pre:  Cert */
/* Post: No fa res si m és NULL, sinó allibera
   espai dels nodes del heap apuntat per m */
  if (m != NULL) {
    esborra_nodes(m->fesq);
    esborra_nodes(m->fdret);
    delete m;
  }
};

template <typename T>
heap<T>::heap(heap<T>& he, const T& x, heap<T>& hd) {
  _arrel = new node;
  try {
    _arrel->info = x;
  }
  catch (...) {
    delete _arrel;
    throw;
  }
  _arrel->fesq = he._arrel;
  if(he._arrel != NULL) {
    he._arrel->pare = _arrel;
    he._arrel = NULL;
  }
  _arrel->fdret = hd._arrel;
  if(hd._arrel != NULL) {
    hd._arrel->pare = _arrel;
    hd._arrel = NULL;
  }
  _nelems = he._nelems + hd._nelems + 1;
}

template <typename T>
heap<T>::heap(const heap<T> &h) {
  _arrel = copia_nodes(h._arrel, NULL);
  _nelems = h._nelems;
};

template <typename T>
heap<T>::~heap() {
  esborra_nodes(_arrel);
};

template <typename T>
bool heap<T>::empty() const {
  return _nelems == 0;
}

template <typename T>
T heap<T>::min() const {
  return _arrel->info;
}

template <typename T>
void heap<T>::ultim(node* &ult, node* &pare_ult) const {
  ult = pare_ult = NULL;
  if (_nelems == 1) {
    ult = _arrel;
  } else if (_nelems > 1) {
    stack<bool> s;
    nat i = _nelems;
    while (i > 1) {
      s.push(i%2 == 0);
      i /= 2;
    }
    ult = _arrel;
    while (not s.empty()) {
      pare_ult = ult;
      if (s.top())
        ult = ult->fesq;
      else
        ult = ult->fdret;
      s.pop();
    }
  }
}


// D'un heap de n elements en total, llegeix des de cin el subheap de la posició i
heap<int> llegir_heap(int i, int n) {
  if (i <= n) {
    int valor;
    cin >> valor;
    heap<int> he(llegir_heap(i*2, n));
    heap<int> hd(llegir_heap(i*2+1, n));
    return heap<int>(he, valor, hd);
  } else {
    return heap<int>();
  }
}

// Llegeix un heap des de cin i el retorna.
// A cin hi ha el nombre d'elements seguit del recorregut en preordre de l'arbre binari del heap.
heap<int> llegir_heap() {
  nat n;
  cin >> n;
  return llegir_heap(1, n);
}


int main() {
  heap<int> h(llegir_heap());
  while (not h.empty()) {
    cout << h.min() << " ";
    h.elim_min();
  }
  cout << endl;
  return 0;
}
