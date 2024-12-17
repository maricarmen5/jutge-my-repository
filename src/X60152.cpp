#include <iostream>
using namespace std;

int main () 
{
    char conductor;
    double nivell_alcohol;
    int anys = 0;

    cin >> conductor >> nivell_alcohol;
    if (conductor == 'p') cin >> anys;

    if ((conductor == 'p' or (conductor == 'n' and anys < 2)) and
    (0.15 < nivell_alcohol or (2 <= anys and 0.25 < nivell_alcohol))) {
        cout << "Ha de ser sancionat" << endl;
    } 
    else cout << "Pot continuar conduint" << endl;
}