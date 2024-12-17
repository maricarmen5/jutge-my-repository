#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    int n;
    while (cin >> n) {
        if (n == 0) cout << endl;
        else {
            vector<int> v(n);
            int i = 0;
            while (i < n) {
                cin >> v[i];
                ++i;
            }

            i = n - 1;
            while (0 < i) {
                cout << v[i] << ' ';
                --i;
            }
            cout << v[i] << endl;
        }
    }
}
