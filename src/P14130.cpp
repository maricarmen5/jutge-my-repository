#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    int n;
    cin >> n;
    vector<int> v(n);
    int i = 0;
    while (i < n) {
        cin >> v[i];
        ++i;
    }

    int j = 0, mida = v.size() - 1, compt = 0;
    while (j < mida) {
        if (v[j] == v[mida]) ++compt;
        ++j;
    }
    cout << compt << endl;
}
