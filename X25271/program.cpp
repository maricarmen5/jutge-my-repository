#include <iostream>
#include "arbreBin.hpp"
using namespace std;

bool sumaDeFills(arbreBin<int> a) {
    bool compleix = true;
    if (not a.es_buit() and not(a.fd().es_buit() and a.fe().es_buit())) {
        int valorFD = 0;
        if (sumaDeFills(a.fd())) {
            if (not a.fd().es_buit()) valorFD = a.fd().arrel();
            if (sumaDeFills(a.fe())) {
                int valorFE = 0;
                if (not a.fe().es_buit()) valorFE = a.fe().arrel();
                if (valorFD+valorFE != a.arrel()) compleix = false;
            }
            else compleix = false;
        }
        else compleix = false;
    }
    return compleix;
}

int main() {
    arbreBin<int> arbre;
    cin >> arbre;
    bool compleix = sumaDeFills(arbre);
    cout << arbre << endl;
    
    cout << "L'arbre ";
    if (not compleix) cout << "no ";
    cout << "compleix la propietat 'Suma dels fills'." << endl;
}