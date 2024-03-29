#include <iostream>
#include <vector>
using namespace std;

int factorial(int n) 
{
    int f = 1;
    if (1 < n) f = n*factorial(n - 1);
    return f;
}
