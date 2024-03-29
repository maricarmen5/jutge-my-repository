#include <iostream>
using namespace std;

int suma_digits(int n) 
{
    int s = n;
    if (9 < n) s = (n%10) + suma_digits(n/10);
    return s;
}

bool es_multiple_3(int n) 
{
    bool trobat;
    int s = suma_digits(n);
    if (s < 10) {
        if (s == 0 or s == 3 or s == 6 or s == 9) trobat = true;
        else trobat = false;
    } 
    else trobat = es_multiple_3(s);
  
    return trobat;
}
