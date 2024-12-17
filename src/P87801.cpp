#include <iostream>
#include <vector>
using namespace std;
typedef vector< vector<char> > MatriuChar;
typedef vector< vector<int> > MatriuInt;

int obte_puntuacio(string& paraula, MatriuChar& lletra, MatriuInt& puntuacio)
{
    int punts = -1;

    for (unsigned int i = 0; i < lletra.size(); ++i) {
        for (unsigned int j = 0; j < lletra[0].size(); ++j) {
            if (lletra[i][j] == paraula[0]) {
                int p = 0;
                unsigned int x = i;
                unsigned int y = j;
                unsigned int z = 0;
                while (z < paraula.size() and y < lletra[0].size() and lletra[x][y] == paraula[z]) {
                    p += puntuacio[x][y];
                    ++y;
                    ++z;
                }
                if (z == paraula.size()) punts = max(punts, p);

                p = 0;
                y = j;
                z = 0;
                while (z < paraula.size() and x < lletra.size() and lletra[x][y] == paraula[z]) {
                    p += puntuacio[x][y];
                    ++x;
                    ++z;
                }
                if (z == paraula.size()) punts = max(punts, p);
            }
        }
    }

    return punts;
}

int main () 
{
    int f;
    while (cin >> f) {
        int c;
        cin >> c;

        MatriuChar lletra(f, vector<char>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) cin >> lletra[i][j];
        }
        MatriuInt puntuacio(f, vector<int>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) cin >> puntuacio[i][j];
        }
        
        int t;
        cin >> t;
        string paraula;
        for (int i = 0; i < t; ++i) {
            cin >> paraula;
            int punts = obte_puntuacio(paraula, lletra, puntuacio);

            if (punts == -1) cout << "no" << endl;
            else cout << punts << endl;
        }
    }
}
