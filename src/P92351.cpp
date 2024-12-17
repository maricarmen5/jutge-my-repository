#include <iostream>
using namespace std;

int main () 
{
    int a, b;
    cin >> a >> b;
    
    int d = a/b;
    int r = a%b;

    if (a < 0 and r != 0) {
        d -= 1;
        r = a - d*b;
    } 

    cout << d << ' ' << r << endl;
}
