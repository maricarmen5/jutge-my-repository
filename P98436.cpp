#include <iostream>
using namespace std;

class Arbre {
  private:
    struct node {
      node* f_esq;
      node* f_dret;
      int info;
    };
    node* _arrel;

// Pre: `n` és la referència a un node d'un arbre (pot ser nullptr). `k` és un valor enter a inserir,
//       seguit d'una successió de valors llegits per cin (amb -1 com a marcador de nul·litat).
// Post: Retorna el punter a l'arrel del subarbre construït en preordre segons els valors de `cin`.
// Cost temporal: O(n), on n és el nombre total d'elements llegits fins a completar l'arbre.
    node* insereix_preodre_aux(node* n, int k) {
      if (k != -1) {
        n = new node;
        n->info = k;

        cin >> k;
        n->f_esq = insereix_preodre_aux(nullptr, k);

        cin >> k;
        n->f_dret = insereix_preodre_aux(nullptr, k);
      }

      return n;
    }

// Pre: `arrel` és la referència a un node d'un arbre o nullptr.
// Post: Escriu en ordre postordre (esquerra -> dreta -> arrel) les claus de l'arbre/subarbre
//       amb arrel `arrel`, separades per espais.
// Cost temporal: O(n), on n és el nombre total de nodes del subarbre amb arrel `arrel` 
//       (es visita cada node exactament una vegada).
    void print_postordre_aux(node* arrel) const {
      if (arrel != nullptr) {
        print_postordre_aux(arrel->f_esq);
        print_postordre_aux(arrel->f_dret);
        cout << ' ' << arrel->info;
      }
    }

// Pre: `arrel` és la referència a un node d'un arbre o nullptr.
// Post: Escriu en ordre inordre (esquerra -> arrel -> dreta) les claus de l'arbre/subarbre
//       amb arrel `arrel`, separades per espais.
// Cost temporal: O(n), on n és el nombre total de nodes del subarbre amb arrel `arrel` 
//       (es visita cada node exactament una vegada).
    void print_inordre_aux(node* arrel) const {
      if (arrel != nullptr) {
        print_inordre_aux(arrel->f_esq);
        cout << ' ' << arrel->info;
        print_inordre_aux(arrel->f_dret);
      }
    }

  public:
  Arbre(): _arrel(NULL) {};

  void insereix_preodre(int k) {
    _arrel = insereix_preodre_aux(nullptr, k);
  }

  void print_postordre() const {
    print_postordre_aux(_arrel);
  }

  void print_inordre() const {
    print_inordre_aux(_arrel);
  }
};

int main() {
  Arbre bst;

  int k;
  cin >> k;
  bst.insereix_preodre(k);

  cout << "pos:";
  bst.print_postordre();
  cout << endl;

  cout << "ino:";
  bst.print_inordre();
  cout << endl;
}
