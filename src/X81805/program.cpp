#include <iostream>
#include "arbreBin.hpp"
using namespace std;

arbreBin<int> arbreDeSumes(arbreBin<int> a) {
    int arrel = a.arrel();
    arbreBin<int> fillEsquerre;
    if (not a.fe().es_buit()) {
        fillEsquerre = arbreDeSumes(a.fe());
        arrel += fillEsquerre.arrel();
    }
    arbreBin<int> fillDret;
    if (not a.fd().es_buit()) {
        fillDret = arbreDeSumes(a.fd());
        arrel += fillDret.arrel();
    }
    arbreBin<int> arbre = arbreBin<int>(arrel, fillEsquerre, fillDret);
    return arbre;
}

int main() {
    arbreBin<int> arbre;
    cin >> arbre;
    arbreBin<int> arbre_de_sumes;
    if (arbre.es_buit()) arbre_de_sumes = arbre;
    else arbre_de_sumes = arbreDeSumes(arbre);
    cout << arbre_de_sumes << endl;
}