#include <iostream>
using namespace std;

int main () 
{
    int n;
    while (cin >> n) {
        int i = 0;
        while (i < n) {
            int j = 0;
            while (j < n) {
                cout << n;
                ++j;
            }
            cout << endl;
            
            ++i;
        }

        cout << endl;
    }
}
