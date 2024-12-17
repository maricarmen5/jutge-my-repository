#include <iostream>
using namespace std;

int valencia(int n) 
{
    int resultat = 0;
    
    int signe = 1;
    while (n != 0) {
        int digit = signe*(n%10);
        resultat += digit;

        signe = -signe;
        n /= 10;
    }

    if (resultat < 0) resultat = -resultat;
    return resultat;
}

int main () 
{
    int equilibrat = 0;
    int val_max = -1;
    bool trobat = false;
    int n;
    while (cin >> n) {
        int val = valencia(n);
        if (val == 0 and (not trobat)) {
            equilibrat = n;
            trobat = true;
        }
        if (val_max < val) val_max = val; 
    }

    if (trobat) {
        cout << "El primer nombre equilibrat es ";
        cout << equilibrat << '.' << endl;
    }
    else {
        cout << "La valencia maxima es ";
        cout << val_max << '.' << endl;
    }
}
