#include <iostream>
using namespace std;

int main () 
{
    int n;
    cin >> n;
    
    int i = n;
    while (0 < i) {
        cout << i << endl;
        if (i%5 == 0) cout << "Beep" << endl;
        --i;
    }
}