#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<int> > Matriu;

bool es_solucio_sudoku(Matriu& m)
{
    bool resposta = true;

    vector<int> digitsFila(9, -1);
    vector<int> digitsColumna(9, -1);
    vector<int> digitsSubmatriu(9, -1);

    int indexMatriu[9] = {0, 3, 6, 30, 33, 36, 60, 63, 66};
    int indexSubmatriu[9] = {0, 1, 2, 10, 11, 12, 20, 21, 22};
    int i = 0;
    while (resposta and i < 9) {
        int j = 0;
        while (resposta and j < 9) {
            int index = indexMatriu[i] + indexSubmatriu[j];
            ++digitsSubmatriu[m[index/10][index%10] - 1];
            ++digitsFila[m[i][j] - 1];
            ++digitsColumna[m[j][i] - 1];

            if (i != digitsFila[m[i][j] - 1] or
            i != digitsColumna[m[j][i] - 1] or
            i != digitsSubmatriu[m[index/10][index%10] - 1]) {
                resposta = false;
            }

            ++j;
        }
        ++i;
    }

    return resposta;
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

        bool solucio = es_solucio_sudoku(m);
        if (solucio) cout << "si" << endl;
        else cout << "no" << endl;
    }
}
