#include <iostream>
using namespace std;

int main () 
{
    string p1, p2;
    cin >> p1 >> p2;
    if (p1 < p2) swap(p1, p2);

    string p;
    while (cin >> p) {
        if (p1 == p2) p2 = p;
        
        if (p2 < p) {
            swap(p2, p);
            if (p1 < p2) swap(p1, p2);
        }
    }

    cout << p2 << endl;
}

