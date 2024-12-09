#include <iostream>
#include <vector>
using namespace std;
typedef unsigned int nat;

template <typename Clau>
class bst {

  public:
    // Constructora per defecte. Crea un BST buit.
    bst();

    // Destructora
    ~bst();

    // Aquí va l’especificació dels mètodes públics addicionals

    void insereix(const Clau& k);

    template <typename T>
    void recorregut_inordre(vector<T>& v);

  private:
    struct node {
      Clau _k;      // Clau
      node* _esq;   // fill esquerre
      node* _dret;  // fill dret
    };
    node *_arrel;

    static void esborra_nodes(node* m);

    // Aquí va l’especificació dels mètodes privats addicionals

    void insereix_aux(node*& arrel, const Clau& k);

    template <typename T>
    void recorregut_inordre_aux(node*& arrel, int& i, vector<T>& v);
};

// Aquí va la implementació dels mètodes públics i privats de bst

/* Pre: Cap (el BST pot estar buit o no).  
   Post: Insereix la clau k al BST si no hi és.  
   Cost: O(h), on h és l'alçada del BST. */
template <typename Clau>
void bst<Clau>::insereix(const Clau& k) {
    insereix_aux(_arrel, k);
}

/* Pre: Cap (l'arbre pot ser buit).  
   Post: Omple el vector v amb les claus del BST en ordre creixent.  
   Cost: O(n), on n és el nombre de nodes del BST. */
template <typename Clau>
template <typename T>
void bst<Clau>::recorregut_inordre(vector<T>& v) {
    int i = -1;
    recorregut_inordre_aux(_arrel, i, v);
}

/* Pre: arrel apunta a un node vàlid o és nullptr; k és la clau a inserir.  
   Post: Insereix la clau k en l'arbre, mantenint la propietat del BST.  
   Cost: O(h), on h és l'alçada del BST. */
template <typename Clau>
void bst<Clau>::insereix_aux(node*& arrel, const Clau& k) {
    if (arrel == nullptr) {
        arrel = new node;
        arrel->_k = k;
        arrel->_dret = nullptr;
        arrel->_esq = nullptr;
    }
    else if (k < arrel->_k) insereix_aux(arrel->_esq, k);
    else insereix_aux(arrel->_dret, k);
}

/* Pre: Cap (l'arbre pot ser buit).  
   Post: Omple el vector v amb les claus del BST en ordre creixent.  
   Cost: O(n), on n és el nombre de nodes del BST. */
template <typename Clau>
template <typename T>
void bst<Clau>::recorregut_inordre_aux(node*& arrel, int& i, vector<T>& v) {
    if (arrel != nullptr) {
        recorregut_inordre_aux(arrel->_esq, i, v);

        ++i;
        v[i] = arrel->_k;

        recorregut_inordre_aux(arrel->_dret, i, v);
    }
}

// Aquí va la implementació del procediment ordena
template <typename T>
void ordena(vector<T>& v) {
    bst<T> bst;
    for (nat i = 0; i < v.size(); ++i) bst.insereix(v[i]);

    bst.recorregut_inordre(v);
}