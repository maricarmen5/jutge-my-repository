#include <iostream>
#include <vector>
using namespace std;

typedef vector< vector<char> > Matriu1;
typedef vector< vector<int> > Matriu2;

int puntuacio(string& s, Matriu1& m1, Matriu2& m2) 
{
    int ll;
    int f = m1.size();
    int c = m1[0].size();
    int l = s.length();
    int p = -1, pmax=-1;
    for (int i = 0; i <= (f-l); ++i) {
        for (j=0; j<c; ++j) {
            if (s[0]==m1[i][j]) {
                ll=0, p=0;
                bool trobat=false;
                while ((ll<l)and(not trobat)) {
                    // Es llegeix string s horitzontalment fins s(0+ll)
                    if (s[0+ll]!=m1[i+ll][j]) {
                        trobat=true;
                    } else {
                        p+=m2[i+ll][j];
                        ++ll;
                    }
                }
                if (trobat) p=-1;
                pmax=max(p, pmax);
            }
        }
    }
    for (int j=0; j<=(c-l); ++j) {
        for (i=0; i<f; ++i) {
            if (s[0]==m1[i][j]) {
                ll=0, p=0;
                bool trobat=false;
                while ((ll<l)and(not trobat)) {
                    // Es llegeix string s verticalment fins s(0+ll).
                    if (s[0+ll]!=m1[i][j+ll]) {
                        trobat=true;
                    } else {
                        p+=m2[i][j+ll];
                        ++ll;
                    }
                }
                if (trobat) p=-1;
                pmax=max(p, pmax);
            }
        }
    }
    return pmax;
}

int main () 
{
    int f;
    while (cin >> f) {
        int c;
        cin >> c;
        Matriu1 m1(f, vector<char>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) cin >> m1[i][j];
        }
      
        Matriu2 m2(f, vector<int>(c));
        for (int i = 0; i < f; ++i) {
            for (int j = 0; j < c; ++j) cin >> m2[i][j];
        }
      
        int p;
        cin >> p;
        vector<string> v(p);
        for (int i = 0; i < p; ++i) cin >> v[i];
        
        for (int i = 0; i < p; ++i) {
            int puntuacio = puntuacio(v[i], m1, m2);
            if (puntuacio < 0) cout << "no";
            else cout << puntuacio;
            cout << endl;
        }
    }
}
