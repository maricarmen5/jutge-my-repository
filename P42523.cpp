#include <iostream>
using namespace std;

int mcd(int a, int b) 
{
    int m = b;
    
    if (b == 0) m = a;
    else if (a != 0) m = mcd(b, a%b);

    return m;
}

int main () {}
