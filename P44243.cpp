#include <iostream>
#include <vector>

using namespace std;

typedef vector< vector<char> > Matriu;

Matriu espiral(const int& a) {
    Matriu m(a, vector<char>(a, '.'));
    int cont;
    int i=a-1;
    int j=0;
    int x;
    int l=1;
    for (x=a; 0<x; --x) {
        if (l%4==1) {
            for (cont=0; cont<x; ++cont) {
                m[i][j+cont]='X';
            }
            --i;
            j+=x-1;
        } else if (l%4==2) {
            for (cont=0; cont<x; ++cont) {
                m[i-cont][j]='X';
            }
            i-=x-1;
            --j;
        } else if (l%4==3) {
            for (cont=0; cont<x; ++cont) {
                m[i][j-cont]='X';
            }
            ++i;
            j-=x-1;
        } else {
            for (cont=0; cont<x; ++cont) {
                m[i+cont][j]='X';
            }
            i+=x-1;
            ++j;
        }
        ++l;
    }
    return m;
}

int main () {
    int a, i, j;
    Matriu m;
    cin>>a;
    while (a!=0) {
        m=espiral(a);
        for (i=0; i<a; ++i) {
            for (j=0; j<a; ++j) {
                cout<<m[i][j];
            }
            cout<<endl;
        }
        cout << endl;
        cin >> a;
    }
}
