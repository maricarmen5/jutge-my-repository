#include <iostream>
using namespace std;

int main () 
{   
    int n;
    cin >> n;
    char digit = ' ';

    char resultat = ' ';
    int torn = 0;
    while (resultat == ' ') {
        string nombre;
        cin >> nombre;

        int lenght = nombre.length();
        char digit_actual = nombre[lenght/2];
        if (torn == 0) digit = digit_actual;

        if (lenght%2 == 0 or digit_actual != digit) {
            if (torn%2 == 0) resultat = 'B';
            else resultat = 'A';
        }
        else if (torn == 2*n - 1) resultat = '=';

        ++torn;
    }
    
    cout << resultat << endl;
}
