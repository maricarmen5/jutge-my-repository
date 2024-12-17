#include <iostream>
#include <cmath>
using namespace std;

int suma_digits(int n) 
{
    int s = n;
    if (9 < n) s = (n%10) + suma_digits(n/10);
    return s;
}

bool es_primer_perfecte(int n) 
{
    bool trobat = true;
    if (n<=1) trobat = false;
    int i = 2;
    while (i <= sqrt(n) and trobat) {
        // n no es divisible per cap element de (2,...,i)
        if (n%i == 0) trobat = false;
        ++i;
    }
  
    if (10 <= n and trobat) trobat = es_primer_perfecte(suma_digits(n));
  
    return trobat;
}
