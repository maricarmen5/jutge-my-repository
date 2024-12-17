#include <iostream>
#include <vector>
using namespace std;

int main ()
{
    unsigned int n;
    cin >> n;
    vector<string> noms(n);
    vector<int> preus(n);

    unsigned int i = 0;
    while (i < n) {
        cin >> noms[i] >> preus[i];
        ++i;
    }
    
    int preu_real;
    cin >> preu_real;

    int index = -1;
    i = 0;
    while (i < n) {
        if (preus[i] <= preu_real) {
            if (index == -1) index = i;
            else if (preus[index] < preus[i]) index = i;
        }
        ++i;
    }
    
    if (index == -1) cout << "CAP GUANYADOR" << endl;
    else cout << "guanyador/a: " << noms[index] << endl;
}