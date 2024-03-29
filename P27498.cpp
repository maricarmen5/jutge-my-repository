#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

void transposa(Matriu& m) 
{
    int n = m.size();
    for (int i = 0; i < n - 1; ++i) {
        // Inv: elements de fins a la fila anterior a i són transposats
        for (int j = i + 1; j < n; ++j) {
            // Inv: elements fins l'element i-1 j-1 són transposats
            int aux = m[i][j]; 
            m[i][j] = m[j][i];
            m[j][i] = aux;
        }
    }
}
