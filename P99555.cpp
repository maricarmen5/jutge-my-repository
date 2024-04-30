#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

int main () 
{
    int n;
    while (cin >> n) {
        Matriu m(n, vector<int>(n));

        vector<int> digits(n*n, 0);
        vector<int> sumes(n + n + 2, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cin >> m[i][j];
                
                ++digits[m[i][j] - 1];
                sumes[i] += m[i][j];
                sumes[j + n] += m[i][j];
            }

            sumes[n + n] += m[i][i];
            sumes[n + n + 1] += m[i][n - 1 - i];
        }

        bool es_magic_square = true;
        int i = 0;
        while (es_magic_square and i < n + n + 2) {
            if (sumes[i] != (n*(n*n + 1))/2) es_magic_square = false;
            ++i;
        }
        i = 0;
        while (es_magic_square and i < n*n) {
            if (digits[i] != 1) es_magic_square = false;
            ++i;
        }

        if (es_magic_square) cout << "yes" << endl;
        else cout << "no" << endl;
    }
}
