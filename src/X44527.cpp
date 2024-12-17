#include <iostream>
using namespace std;

int main () 
{
    int n;
    cin >> n;
    
    int mida = 2*n + 1;
    int fila = 0;
    while (fila < mida) {
        int columna = 0;
        while (columna < mida) {
            if (columna == fila or columna + fila == mida - 1) cout << 'X';
            else cout << ' ';

            ++columna;
        }

        cout << endl;
        ++fila,
    }
}
