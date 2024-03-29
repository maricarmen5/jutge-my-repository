#include <iostream>
using namespace std;

bool three_equal_consecutive_digits_aux(int n, int b, int consecutives, int last_digit) 
{
    bool ans;
    
    if (n == 0) {
        if (3 <= consecutives) ans = true;
        else ans = false;
    } 
    else {
        int digit = n%b;
        if (digit == last_digit) consecutives++;
        else consecutives = 1;
        if (3 <= consecutives) ans = true;
        else ans = three_equal_consecutive_digits_aux(n/b, b, consecutives, digit);
    }

    return ans;
}

bool three_equal_consecutive_digits(int n, int b) 
{
    bool ans = three_equal_consecutive_digits_aux(n, b, 1, -1);
    return ans;
}
