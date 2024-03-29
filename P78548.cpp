#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    string a;
    while (cin >> a) {
        int i = a.length() - 1;
        while (0 <= i) {
            cout << a[i];
            --i;
        }
        
        cout << endl;
    }
}
