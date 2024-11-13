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