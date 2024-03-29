#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

int main () 
{
    int n, m;
    cin >> n >> m;
    Matriu mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cin >> mat[i][j];
    }

    string question;
    while (cin >> question) {
        int x, y;
        if (question == "fila") {
            cin >> y;
            cout << "fila " << y << ":";
            for (int j = 0; j < m; ++j) cout << ' ' << mat[y-1][j];
        } 
        else if (question == "columna") {
            cin >> x;
            cout << "columna " << x << ":";
            for (int i = 0; i < n; ++i) cout << ' ' << mat[i][x-1];
        } 
        else {
            cin >> x >> y;
            cout << "element " << x << ' ' << y << ": " << mat[x-1][y-1];
        }

        cout << endl;
    }
}
