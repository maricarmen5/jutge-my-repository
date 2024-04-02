#include <iostream>
using namespace std;

int main () 
{
    bool trobat = false;
    int i = 1;
    int n;
    cin >> n;
    while (not trobat) {
        if (n%2 == 0) {
            trobat = true;
            cout << i << endl;  
        }
        cin >> n;
        ++i;
    }
}