#include <iostream>
using namespace std;

int suma_digits(int n) 
{   
    int resultat = 0;
    int digits = n;
    while (digits != 0) {
        resultat += digits%10;
        digits /= 10;
    }
    return resultat;
}

int main () 
{
    int n;
    while (cin >> n) {
        cout << "The sum of the digits of " << n << " is ";
        cout << suma_digits(n) << '.' << endl;
    }
}