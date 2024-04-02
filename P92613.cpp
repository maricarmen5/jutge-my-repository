#include <iostream>
using namespace std;

int main () 
{
    double x;
    cin >> x;
    
    int integer = (int)x;
    double decimal = x - integer;

    cout << integer << ' ';

    if (decimal == 0) cout << x << ' ';
    else cout << integer + 1 << ' ';

    if (decimal < 0.5) cout << integer << endl;
    else cout << integer + 1 <<endl;
}
