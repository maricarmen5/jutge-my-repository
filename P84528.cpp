#include <iostream>
#include <vector>
using namespace std;

typedef vector < vector<char> > Matrix;

Matrix read_matrix(int f, int c) 
{
    Matrix m(f, vector<char> (c));
    for (int i = 0; i < f; ++i) {
        for (int j=0; j<c; ++j) cin >> m[i][j];
    }
    return m;
}

void write_matrix(Matrix m) 
{
    for (unsigned int i=0; i<m.size(); ++i) {
        //Inv:i raws are shown.
        for (unsigned int j=0; j<m[0].size(); ++j) {
            //Inv:j elements of raw i are shown.
            cout<<m[i][j];
        }
        cout<<endl;
    }
}

int coordenaday(string s) {
    int resp = 0;
    for (unsigned int i = 1; i < s.size(); ++i) {
        int n = s[s.size() - i] - 48;
        int p = 1;
        for (unsigned int j=1; j<i; ++j) p *= 10;
        resp += n*p;
    }
    return resp;
}

int main () 
{
    int f, c;
    cin >> f >> c;
    Matrix graella(f, vector<char> (c));
    graella = read_matrix(f, c);

    string tret;
    while (cin >> tret) {
        cout << tret << ": ";

        int x = tret[0] - 97;
        int y = coordenaday(tret);
        if (graella[x][y] == '.') cout << "aigua";
        else {
            graella[x][y] = 'T';

            int esq = y - 1;
            int dre = y + 1;
            bool tocat = false;
            while ((not tocat) and graella[x][esq] != '.') {
                // Inv:no sé si el vaixell està enfonsat o tocat
                if (graella[x][esq] == 'V') tocat = true;
                --esq;
            }
            while ((not tocat)and graella[x][dre] != '.') {
                // Inv:no sé si el vaixell està enfonsat o tocat
                if (graella[x][dre] == 'V') tocat = true;
                ++dre;
            }

            if (tocat) cout << "tocat";
            else {
                cout << "enfonsat";
                esq = y - 1;
                dre = y + 1;
                graella[x][y] = '.';
                // posar aigua
                while (graella[x][esq] != '.') { 
                    graella[x][esq] = '.';
                    --esq;
                }
                while (graella[x][dre] != '.') {
                    graella[x][dre] = '.';
                    ++dre;
                }
            }
        }
        cout << endl;
    }

    cout << endl;
    write_matrix(graella);
}