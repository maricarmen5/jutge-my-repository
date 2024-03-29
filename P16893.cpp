#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

bool es_solucio_sudoku(const Matriu& m) 
{
    vector<int> repeticions(9, 0);

    bool correcte = true;
    int i = 0;
    int j = 0;
    while (correcte and i < 9) { //  comprova per files
        j = 0;
        while (correcte and j < 9) {
            int n = m[i][j] - 1;
            ++repeticions[n];

            if (i + 1 < repeticions[n]) correcte = false;
            ++j;
        }

        ++i;
    }

    j = 0;
    while (correcte and j < 9) { //  comprova per columnes
        i = 0;
        while (correcte and i < 9) {
            int n = m[i][j] - 1;
            ++repeticions[n];

            if (j + 10 < repeticions[n]) correcte = false;
            ++i;
        }

        ++j;
    }

    int submatriu = 0;
    i = 0;
    j = 0;
    while (correcte and submatriu < 9) { // comprova submatrius 3 x 3
        int fila = 0;
        while (correcte and fila < 3) {
            int columna = 0;
            while (correcte and columna < 3) {
                int n = m[i][j + columna] - 1;
                ++repeticions[n];

                if (submatriu + 19 < repeticions[n]) correcte = false;
                ++columna;
            }

            ++fila;
        }

        if (j == 6) {
            i += 3;
            j = 0;
        }
        else j += 3;
        ++submatriu;
    }

    return correcte;
}

int main () 
{
    Matriu m(9, vector<int>(9));

    int casos;
    cin >> casos;
    for (int cas = 0; cas < casos; ++cas) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) cin >> m[i][j];
        }

        if (es_solucio_sudoku(m)) cout << "si";
        else cout << "no";
        cout << endl;
    }
}
