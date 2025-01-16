#include <iostream>
using namespace std;
typedef unsigned int nat;

class dicc {
// Diccionari implementat amb un TST on les claus són strings i els
// símbols de la clau són chars. El símbol indicador fi de clau és el #
public:
  // Constructora per defecte. Crea un diccionari buit.
  dicc();

  // Destructora
  ~dicc();

  // Insereix la clau k en el diccionari. Si ja hi era, no fa res.
  void insereix(const string &k);

  nat quantes_satisfan_patro(string patro) const;
  // Pre: patro conté símbols de la A a la Z o el símbol comodí *
  // Post: Retorna el nº de claus que coincideixen amb el patro donat.
  // El símbol * equival a qualsevol símbol de la A a la Z.

private:
  struct node {
    char _c;    // Símbol posició i-èssima de la clau
    node* _esq; // Fill esquerra, apunta a símbols mateixa posició formant un BST
    node* _cen; // Fill central, apunta a símbols següent posició
    node* _dre; // Fill dret, apunta a símbols mateixa posició formant un BST
    node(const char &c, node* esq = nullptr, node* cen = nullptr, node* dre = nullptr);
  };
  node* _arrel;

  static void esborra_nodes(node* t);
  static node* insereix(node *t, nat i, const string &k);

  // Aquí va l’especificació dels mètodes privats addicionals
  nat quantes_satisfan_patro_aux(node* t, nat i, string& patro) const;
};

// Aquí va la implementació del mètode públic i dels mètodes privats addicionals

nat dicc::quantes_satisfan_patro(string patro) const {
  string p = patro+'#';
  nat quantes = quantes_satisfan_patro_aux(_arrel, 0, p);
  return quantes;
}

/**
 * Pre: t pot ser nul, i < p.size(), p acaba amb #.
 * Post: retorna el nombre de paraules apuntades per t que compleixen el patro p
 */
nat dicc::quantes_satisfan_patro_aux(node* t, nat i, string& p) const {
  nat quantes = 0;

  if (t != nullptr and i < p.size()) {
    if (p[i] == '*') {
      quantes = quantes_satisfan_patro_aux(t->_esq, i, p);
      quantes += quantes_satisfan_patro_aux(t->_cen, i+1, p);
      quantes += quantes_satisfan_patro_aux(t->_dre, i, p);
    }
    else if (p[i] < t->_c) quantes = quantes_satisfan_patro_aux(t->_esq, i, p);
    else if (t->_c < p[i]) quantes = quantes_satisfan_patro_aux(t->_dre, i, p);
    else if (p[i] != '#') quantes = quantes_satisfan_patro_aux(t->_cen, i+1, p);
    else quantes = 1;
  }

  return quantes;
}