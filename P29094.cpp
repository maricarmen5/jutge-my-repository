#include <iostream>
#include <vector>
using namespace std;

int posicio_maxim(const vector<double>& v, int m) 
{
    double max = v[0];
    int p = 0;
    for (int i = 0; i <= m; ++i) {
        // max és el màxim del subvector (0..i).
        if (max < v[i]) {
            max = v[i];
            p = i;
        }
    }
  
    return p;
}
