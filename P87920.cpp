#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    int n;
    while (cin >> n) {
        vector<int> v(n);
        int suma = 0;

        int i = 0;
        while (i < n) {
            cin >> v[i];
            suma += v[i];
            ++i;
        }

        bool trobat = false;
        i = 0;
        while (i < n and (not trobat)) {
            if (v[i] == suma - v[i]) trobat = true;
            ++i;
        }

        if (trobat) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
