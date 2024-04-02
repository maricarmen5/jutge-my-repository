#include <iostream>
using namespace std;

bool es_triangle_rectangle(int a, int b, int c) 
{
    bool r = false;
    if (a*a + b*b == c*c or a*a + c*c == b*b or b*b + c*c == a*a) r = true;
    return r;
}

int main () 
{
    int i = 0;

    int a, b, c, x1, x2, x3, x;
    cin >> x1 >> x2;
    while (cin >> x3) {
        a = x1;
        b = x2;
        c = x3;
        if (es_triangle_rectangle(a, b, c)) ++i;

        x1 = x2;
        x2 = x3;
    }

    cout << i << endl;
}