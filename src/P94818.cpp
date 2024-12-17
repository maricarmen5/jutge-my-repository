#include <iostream>
#include <cstddef>
#include <iomanip>
using namespace std;

template <typename Clau>
class Dicc {
  private:
    struct node {
      node* f_esq;
      node* f_dret;
      Clau _k;
    };
    node* _arrel;

// Pre: `n` és la referència a un node d'un BST, pot ser nullptr. `k` és una clau que es vol inserir.
// Post: Retorna el punter a l'arrel del subarbre resultant amb `k` inserida correctament. Si `k` ja hi era, no fa res.
// Cost temporal: O(h), on h és l'altura de l'arbre. En el pitjor cas, h = O(n) per un arbre degenerat.
    node* insereix_aux(node* n, const Clau &k) {
        if (n == nullptr) {
            n = new node;
            n->_k = k;
            n->f_dret = nullptr;
            n->f_esq = nullptr;
        } 
        else if (k < n->_k) n->f_esq = insereix_aux(n->f_esq, k);
        else if (n->_k < k) n->f_dret = insereix_aux(n->f_dret, k);

        return n;
    }

// Pre: `n` és la referència a un node d'un BST o nullptr. `nivell` indica el nivell actual a imprimir.
// Post: Escriu les claus del subarbre amb arrel `n` en ordre descendent (dreta -> arrel -> esquerra),
//       amb una indentació proporcional al nivell.
// Cost temporal: O(n), on n és el nombre total de nodes del subarbre amb arrel `n` (es visita cada node exactament una vegada).
    void print_aux(node* n, int nivell) const {
        if (n != nullptr) {
            print_aux(n->f_dret, nivell+1);
            cout << setw(10*nivell) << n->_k << endl;
            print_aux(n->f_esq, nivell+1);
        }
    }

  public:
  Dicc(): _arrel(NULL) {};

  void insereix(const Clau &k) {
    _arrel = insereix_aux(_arrel, k);
  }

  void print() const {
    print_aux(_arrel, 1);
  }
};

int main() {
    Dicc<int> bst;

    int a;
    while (cin >> a) bst.insereix(a);

    bst.print();
}
