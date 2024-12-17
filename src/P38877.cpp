#include <iostream>
using namespace std;

void gira_paraules(int& n)
{
    string s;
    if (cin >> s) {
        gira_paraules(n);
        if (0 <= n) cout << s << endl;
    }
    --n;
}

int main () 
{
    int n;
    cin >> n;
    gira_paraules(n);
}
