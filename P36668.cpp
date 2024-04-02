#include <iostream>
using namespace std;

int main () 
{
    int n;
    cin >> n;

    int result = 0;
    int i = 1;
    while (i <= n) {
        result += i*i;
        ++i;
    }

    cout << result << endl;
}