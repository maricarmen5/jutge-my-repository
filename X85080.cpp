#include <iostream>
#include <vector>
using namespace std;

struct producte {
  int codi;
  double preu;
  int unitats;
};

int main()
{
    int nombreProductes;
    cin >> nombreProductes;
    vector<Producte> productes(nombreProductes);
    for (int i = 0; i < nombreProductes; ++i) {
        int codi;
        double preu;
        cin >> codi >> preu;

        productes[i] = {codi, preu, 0};
    }
    
    int productesDiferents = 0;
    double total = 0;
    double descompte = 0;

    int compra;
    cin >> compra;
    while (compra != -1) {
        int i = 0;
        while (compra != productes[i].codi) ++i;
        
        ++productes[i].unitats;
        if (productes[i].unitats == 1) ++productesDiferents;
        if (productes[i].unitats%3 == 0) descompte -= productes[i].preu;
        total += productes[i].preu;    

        cin >> compra;
    }

    cout << "Productes diferents: " << productesDiferents << endl;
    cout << "Total sense descompte: " << total << endl;
    cout << "Descompte: " << descompte << endl;
    cout << "Total amb descompte: " << total + descompte << endl;
}
