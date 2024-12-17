#include <iostream>
using namespace std;

int main () 
{
    int i;
    cin >> i;
    
    int x;
    int j = 0;
    while (j < i) {
        cin >> x;
        ++j;
    }
    
    cout << "At the position " << i << " there is a(n) " << x << '.';
    cout << endl;
}