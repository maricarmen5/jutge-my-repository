#include <iostream>
using namespace std;

bool three_equal_consecutive_digits_aux(int n, int b, int consecutives, int last_digit) 
{
    bool answer = true;
    
    if (n == 0) answer = false;
    else {
        int digit = n%b;
        
        if (digit == last_digit) ++consecutives;
        else consecutives = 1;
        
        if (consecutives < 3) answer = three_equal_consecutive_digits_aux(n/b, b, consecutives, digit);
    }

    return answer;
}

bool three_equal_consecutive_digits(int n, int b) 
{
    return three_equal_consecutive_digits_aux(n, b, 1, -1);
}
