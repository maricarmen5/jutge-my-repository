#include <iostream>
#include <cmath>
using namespace std;

int digits(int x) 
{
    int n = 0;

    while (x != 0) {
        x /= 10;
        ++n;
    }

    return n;
}

int concatenacio(int a, int b) 
{
    int i = digits(b);
    int total_digits = digits(a) + i;
    int p = pow(10, i);
    
    while (i < total_digits) {
        b += (a%10)*p;

        ++i;
        a /= 10;
        p *= 10;
    }

    return b;
}

int main() 
{
    int a, b;
    while (cin >> a >> b) cout << concatenacio(a,b) << endl;
}
