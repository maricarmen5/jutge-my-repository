#include <iostream>
#include <sstream>
#include "X68607.hpp"
using namespace std;

int main() {
  string linea, comanda;;
  int n, n1, n2;
  while (getline(cin, linea)) {
    dicc<int> d;

    // Obtenim elements 1er diccionari
    istringstream ss1(linea);
    while (ss1 >> n){
      d.insereix(n);
    }
    d.print(); cout << endl;

    // Processem comandes
    while (getline(cin, linea) and linea != "----------") {
      cout << linea << ": ";
      istringstream ss2(linea);
      ss2 >> comanda;

      if (comanda == "insereix") {
        ss2 >> n;
        d.insereix(n);
        cout << d.quants();

      } else if (comanda == "elimina") {
        ss2 >> n;
        d.elimina(n);
        cout << d.quants();

      } else if (comanda == "consulta") {
        ss2 >> n;
        cout << d.consulta(n);

      } else if (comanda == "quants") {
        cout << d.quants();

      } else if (comanda == "print") {
        d.print();

      } else if (comanda == "print_interval") {
        ss2 >> n1 >> n2;
        d.print_interval(n1, n2);

      } else if (comanda == "min") {
        cout << d.min();

      } else if (comanda == "max") {
        cout << d.max();

      } else if (comanda == "iessim") {
        ss2 >> n;
        cout << d.iessim(n);
      }
      cout<<endl;
    }
    if (linea == "----------")
      cout << linea << endl;
  }
}
