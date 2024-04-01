#include <iostream>
using namespace std;

bool is_leap_year(int year) 
{
    bool is_leap = false;

    if ((year%100 == 0 and (year/100)%4 == 0) or 
    (year%100 != 0 and year%4 == 0)) is_leap = true;

    return is_leap;
}

