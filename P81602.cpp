#include <iostream>
#include <vector>
using namespace std;

int posicio_maxim(const vector<double>& v, int m) 
{
    double max = v[0];
    int p = 0;
    for (int i = 0; i <= m; ++i) {
        // p és la posició del màxim del subector[0...i].
        if (max < v[i]) {
            max = v[i];
            p = i;
        }
    }
  
    return p;
}

void ordena_per_seleccio(vector<double>& v, int m) 
{
    int p;
    double a;
    if (0 < m) {
        p = posicio_maxim(v, m);
        a = v[p];
        v[p] = v[m];
        v[m] = a;
        ordena_per_seleccio(v, m - 1);
    }
}
