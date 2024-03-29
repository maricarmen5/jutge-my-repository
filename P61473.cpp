#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

bool es_simetrica(const Matriu& m) 
{
    int n = m.size();

    bool simetrica = true;
    int i = 0;
    while (simetrica and i < n - 1) {
        // Inv: elements de fins a la fila anterior a i són simètrics
        int j = i + 1;
        while (simetrica and j < n) {
            // Inv: elements fins l'element i-1 j-1 són simètrics
            if (m[i][j] != m[j][i]) simetrica = false;
            ++j;
        }
        
        ++i;
    }

    return simetrica;
}
