#include <iostream>
using namespace std;

int factorial_doble(int n) 
{
    int f = 1;
    if (1 < n) f = n*factorial_doble(n - 2);
    return f;
}
