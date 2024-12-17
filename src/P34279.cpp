#include <iostream>
using namespace std;

int main () 
{
    int x, y, z;
    cin >> x >> y >> z;
    ++z;

    if (z == 60) {
        z = 0;
        ++y;
    }

    if (y == 60) {
        y = 0;
        ++x;
    }

    if (x == 24) x = 0;

    if (0 <= x and x < 10) cout << '0' << x << ':';
    else cout << x << ':';

    if (0 <= y and y < 10) cout << '0' << y << ':';
    else cout << y << ':';

    if (0 <= z and z < 10) cout << '0'; 
    cout << z << endl;
}