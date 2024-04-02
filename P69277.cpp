#include <iostream>
using namespace std;

int main () 
{
    int n;
    cin >> n;

    int i = 0;
    while (i < n) {
        cout << i*i*i << ',';
        ++i;
    }
    cout << i*i*i << endl;
}