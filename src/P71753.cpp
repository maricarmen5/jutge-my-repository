#include <iostream>
using namespace std;

int main () 
{
    int n;
    while (cin >> n) {
        int max;
        cin >> max;

        int x;
        int i = 1;
        while (i < n) {
            cin >> x;
            if (max < x) max = x;
            ++i;
        }

        cout << max << endl;
    }
}