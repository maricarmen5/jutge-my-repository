#include <iostream>
#include <vector>
using namespace std;

int mcd(int a, int b) 
{
    if (a < 0) a *= -1;
    if (b < 0) b *= -1;
    int m, D, d, r;
    if (a == 0) m = b;
    else if (b == 0) m = a;
    else {
        if (a < b) d = a, D = b;
        else d = b, D = a;
        r = D%d;
        if (r == 0) m = d;
        else m = mcd(d, r);
    }
  
    return m;
}
