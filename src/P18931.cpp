#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matrix;

void print_matrix(Matrix m) 
{
    for (unsigned int i = 0; i < m.size(); ++i) {
        for (unsigned int j = 0; j < m[0].size(); ++j) {
            cout << m[i][j];
        }
        cout << endl;
    }
}

void recursive_pattern(Matrix& m, int i, int j, int n)
{
    if (n == 1) m[i][j] = '#';
    else {
        int p = pow(2, n - 1) - 1;

        recursive_pattern(m, i, j, n - 1);
        m[i][j + p] = '#';
        recursive_pattern(m, i, j + p + 1, n - 1);

        m[i + p][j] = '#';
        m[i + p][j + 2*p] = '#';

        recursive_pattern(m, i + p + 1, j, n - 1);
        m[i + 2*p][j + p] = '#';
        recursive_pattern(m, i + p + 1, j + p + 1, n-1);
    }
}

int main () 
{
    int n;
    cin >> n;
    
    int p = pow(2, n) - 1;
    Matrix m(p, vector<char>(p, '.'));
    
    recursive_pattern(m, 0, 0, n);

    print_matrix(m);
}
