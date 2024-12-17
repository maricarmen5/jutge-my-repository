#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<char> > Matriu;

// Troba la amenaça en la direcció (dx,dy) des de la posició (i,j) de M
void threat(int i, int j, const Matriu& M, int dx, int dy) 
{
    int f = M.size();
    int c = M[0].size();
    bool trobat = false;
    int x = i + dx;
    int y = j + dy;
    while (x < f and y < c and 0 <= x and 0 <= y and not trobat) {
        // Inv: encara no s'ha trobat una amenaça
        if (M[x][y] == 'X') {
            cout << '(' << i+1 << ',' << j+1 << ")<->(" << x + 1 << ',' << y + 1 << ')' << endl;
            trobat = true;
        } 
        x += dx;
        y += dy;
    }
}

int main () 
{
    int f, c;
    cin >> f >> c;
    Matriu M(f, vector<char> (c));
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) cin >> M[i][j];
    }
  
    for (int i = 0; i < f; ++i) {
        for (int j = 0; j < c; ++j) {
            if (M[i][j] == 'X') {
                threat(i, j, M, -1, -1);
                threat(i, j, M, -1, 1);
                threat(i, j, M, 1, -1);
                threat(i, j, M, 1, 1);
            }
        }
    }
}
