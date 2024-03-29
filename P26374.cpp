#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

Matriu suma(const Matriu& a, const Matriu& b) 
{
    int n = a.size();
    Matriu c(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) c[i][j] = a[i][j] + b[i][j];
    }
    
    return c;
}
