#include <iostream>
#include <vector>
using namespace std;

// Retorna el valor d'una paraula, suma dels valors 
// de cada lletra (a és 0, b és 1, c és 2, etc.)
int valor(string s) 
{
    int n = 0;
    for (unsigned int i = 0; i < s.size(); ++i) n += s[i] - 97;
    return n;
}

int main () 
{ 
    cout << "----------" << endl;

    int n;
    while (cin >> n) {
        vector<string> u(n);
        vector<int> v(n);
        int vmax = 0;
        for (int i = 0; i < n; ++i) {
            // Inv:vmax és el valor màxim de les i paraules llegides
            cin >> u[i];
            v[i] = valor(u[i]);
            if (vmax < v[i]) vmax = v[i];
        }

        for (int i = 0; i < n; ++i) {
            if (v[i] < vmax) cout << u[i] << endl;
        }

        cout << "----------" << endl;
    }
}