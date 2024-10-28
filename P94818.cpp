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