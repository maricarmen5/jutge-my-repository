#include <iostream>
using namespace std;

int ndigits(int x) 
{
    int a = x;
    int n = 0;

    while (a!=0) {
        a /= 10;
        ++n;
    }
    if (x == 0) n = 1;

    return n;
}

int potencia (int a, int b) 
{
    int c = 1;
    int i = 1;
    while (i <= b) {
        c *= a;
        ++i;
    }

    return c;
}

int concatenacio(int a, int b) 
{
    int esq = a;
    int con = b;
    int i = 0;
    while (i < ndigits(a)) {
        int p = esq%10;
        con += p*(potencia(10, ndigits(b) + i));
        ++i;
        esq /= 10;
    }

    return con;
}

int main() 
{
    int a, b;
    while (cin >> a >> b) {
        cout << concatenacio(a,b) << endl;
    }
}