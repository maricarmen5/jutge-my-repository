#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    vector<int> v(1001, 0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        // l'element x%10000 de v s'incrementa en una unitat
        int x;
        cin >> x;
        ++v[x%10000];
    }

    for (int i = 0; i < 1001; ++i) {
        // freqüència de l'element i de v diferent de 0
        if (v[i] != 0) cout << 1000000000 + i << " : " << v[i] << endl;
    }
}
