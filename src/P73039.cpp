#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    int partides;
    cin >> partides;

    for (int partida = 0; partida < partides; ++partida) {
        char guanya = '=';

        string paraula;
        cin >> paraula;
        char lletra = paraula[paraula.length() - 1];
        
        for (int torn = 0; torn < 9; ++torn) {
            cin >> paraula;
            if (paraula[0] != lletra and guanya == '=') guanya = 65 + torn%2;

            lletra = paraula[paraula.length() - 1];
        }

        cout << guanya << endl;
    }
}
