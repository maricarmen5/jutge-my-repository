#include <iostream>
using namespace std;

void hanoi(int n, char o, char d, char a) 
{
    if (n == 1) cout << o << " => " << d << endl;
    else {
        hanoi(n - 1, o, a, d);
        cout << o << " => " << d << endl;
        hanoi(n - 1, a, d, o);
    }
}

int main () 
{
    int n;
    cin >> n;

    hanoi(n, 'A', 'C', 'B');
}
