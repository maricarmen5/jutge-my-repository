#include <iostream>
using namespace std;

class Dicc {
private:
  struct node {
    node* f_esq;
    node* f_dret;
    int _k;
  };
  node* _arrel;
  
  node* insereix_aux(node* n, int k) {
    if (k != -1) {
      n = new node;
      n->_k = k;

      cin >> k;
      n->f_esq = insereix_aux(nullptr, k);

      cin >> k;
      n->f_dret = insereix_aux(nullptr, k);
    }

    return n;
  }

// Pre: `arrel` és la referència a un node d'un arbre (pot ser nullptr). `k` és un valor enter.
// Post: Retorna true si `k` es troba al subarbre amb arrel `arrel`, i false en cas contrari.
// Cost temporal: O(h), on h és l'altura del subarbre amb arrel `arrel`.
//                En un BST equilibrat, aquest cost és O(log n), on n és el nombre de nodes de l'arbre.
//                En el pitjor cas (BST completament desequilibrat), el cost és O(n).
  bool es_troba_aux(node* arrel, const int& k) {
    bool esTrobaK = false;

    if (arrel != nullptr) {
      if (k == arrel->_k) esTrobaK = true;
      else if (k < arrel->_k) esTrobaK = es_troba_aux(arrel->f_esq, k);
      else esTrobaK = es_troba_aux(arrel->f_dret, k);
    }

    return esTrobaK;
  }

public:
Dicc(): _arrel(NULL) {};

void crea_bst(int k) {
  cin >> k; // arrel del bst
  _arrel = insereix_aux(nullptr, k);
}

bool es_troba(const int& k) {
  bool esTrobaK = es_troba_aux(_arrel, k);
  return esTrobaK;
}
};

int main() {
  Dicc bst;
  int k;
  cin >> k;
  bst.crea_bst(k); // no fem cas a aquest valor k

  int n;
  while (cin >> n) cout << n << ' ' << bst.es_troba(n) << endl;
}
