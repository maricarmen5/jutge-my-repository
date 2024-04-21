#include <iostream>
using namespace std;

int main () 
{
    string p1, p2;
    cin >> p1;
    cin >> p2;
    if (p1 < p2) swap(p1, p2);

    string p;
    while (cin >> p) {
        if (p1 == p2 or p1 == p or p2 == p) {
            p1 = max(max(p1, p2), p);
            p2 = min(min(p1, p2), p);
        }
        else {
            if (p1 < p) swap(p1, p);
            if (p2 < p) swap(p2, p);
        }
    }

    cout << p2 << endl;
}
