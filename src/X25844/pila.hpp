#include <iostream>
 #include <vector>
 using namespace std;
 typedef unsigned int nat;
 
 template <typename T>
 class pila { // pila en memòria dinàmica
   public:
     pila();
     // Crea pila buida
 
     ~pila();
     // Destrueix el p.i.
 
     pila(const vector<int> &v);
     // Crea pila amb els elements de v amb el mateix ordre.
 
     nat longitud() const;
     // Retorna el nombre d’elements del p.i.
 
     void mostra() const;
     // Mostra el p.i. pel canal estàndard de sortida.
 
     void duplica_amb_sumes();
     // Pre: true
     // Post: S’han duplicat els elements de la pila, a sobre de cada element hi ha un
     // nou element que conté la suma dels elements restants de la pila original
 
   private:
     struct node {
       T info;
       node* seg;
     };
     node* _cim; // Apunta al cim de la pila
     nat _mida;  // Nombre d’elements de la pila
 
     // Aquí va l’especificació dels mètodes privats addicionals
 };
 
 // Aquí va la implementació del mètode duplica_amb_sumes i dels privats addicionals
template <typename T>
void pila<T>::duplica_amb_sumes() { // cost lineal 2n
  if (_mida != 0) {
    int suma = 0; 
    node* actual = _cim; 
    while (actual != NULL) { // cost lineal n
      suma += actual->info;
      actual = actual->seg;
    }
    actual = _cim; 
    node* anteior = NULL; 
    while (actual != NULL) { // cost lineal n
      node* nou = new node;
      nou->info = suma;
      nou->seg = actual;
      if (anteior == NULL) _cim = nou;
      else anteior->seg = nou;
      suma -= actual->info;
      anteior = actual;
      actual = actual->seg;
    }
    _mida *= 2; 
  }
}