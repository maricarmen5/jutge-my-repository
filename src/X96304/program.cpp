#include <iostream>
#include <stack>
#include "Punt.hpp"
#include "stackIOpunt.hpp"
using namespace std;

int main ()
{
    stack<Punt> s;
    cin >> s;
    cout << s;

    Punt p;
    while (cin >> p) {
        stack<Punt> t = s;
        bool found = false;

        while ((not t.empty()) and (not found)) {
            if (p == t.top()) found = true;
            else t.pop();
        }

        cout << "El punt " << p;
        if (not found) cout << " no";
        cout << " es troba en la pila." << endl;
    }
}