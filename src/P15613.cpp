#include <iostream>
using namespace std;

int main () 
{
    string a = "cold";
    string b = "ok";
    string c = "hot";
    string d = "water would freeze";
    string e = "water would boil";

    int x;
    cin >> x;

    cout << "it's ";
    if (x <= 0) cout << a << endl << d; 
    else if (x < 10) cout << a;
    else if (x <= 30) cout << b;
    else if (x < 100) cout << c;
    else cout << c << endl << e;
    cout << endl;
}