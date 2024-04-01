#include <iostream>
using namespace std;

bool is_leap_year(int year) 
{
    bool is_leap = false;

    if ((year%100 == 0 and (year/100)%4 == 0) or 
    (year%100 != 0 and year%4 == 0)) is_leap = true;

    return is_leap;
}

bool is_valid_date(int d, int m, int y) 
{
    bool is_valid = false;

    if (0 < d and 0 < m and m < 13) {
        if (m == 4 or m == 6 or m == 9 or m == 11) {
            if (d < 31) is_valid = true;
        }
        else if (m == 2) {
            bool is_leap = is_leap_year(y);

            if ((is_leap and d < 30) or
            (not is_leap and d < 29)) is_valid = true;
        }
        else if (d < 32) is_valid = true;
    }

    return is_valid;
}