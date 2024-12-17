#include <iostream>
using namespace std;

int potencia(int a, int b) 
{
    int resultat = 1;
    int exp = 1;
    while (exp <= b) {
        resultat *= a;
        ++exp;
    }
    return resultat;
}

int main () 
{
    int a, b;
    while (cin >> a >> b) cout << potencia(a,b) << endl;
}
