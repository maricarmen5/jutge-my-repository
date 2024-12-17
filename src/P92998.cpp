#include <iostream>
using namespace std;

void gira_paraules(int& n) 
{
    string s;
    if (cin >> s) {
        gira_paraules(n - 1);
        if (0 < n) cout << s << endl;
    }
}

int main () 
{
    int n;
    cin >> n;
    gira_paraules(n);
}
