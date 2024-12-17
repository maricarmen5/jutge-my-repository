#include <iostream>
using namespace std;

int sum_divisors(int x) 
{
    int sum = 1;
    if (x != 1) sum += x;

    for (int i = 2; i*i <= x; ++i) {
        if (x%i == 0) {
            sum += i + x/i;
            if (i == x/i) sum -= i;
        }
    }

    return sum;
}

int main () {}