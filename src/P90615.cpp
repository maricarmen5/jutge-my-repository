#include <iostream>
using namespace std;

int main() 
{ 
    int x, y, z;
    cin >> x >> y >> z;
    
    int maxim = x;
    if (maxim < y) maxim = y;
    if (maxim < z) maxim = z;
    
    cout << maxim << endl;
}