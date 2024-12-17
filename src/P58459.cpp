bool is_leap_year(int year) 
{
    bool leap = false;
    if ((year%400 == 0) or (year%100 != 0 and year%4 == 0)) leap = true;
    return leap;
}

bool is_valid_date(int d, int m, int y) 
{
    bool valid = false;

    if (0 < d) {
        if ((m == 4 or m == 6 or m == 9 or m == 11) and (d < 31)) valid = true;
        else if ((m == 1 or m == 3 or m == 5 or m == 7 or m == 8 or m == 10 or m == 12) and (d < 32)) valid = true;
        else if (m == 2) {
            bool leap = is_leap_year(y);
            if ((leap and d < 30) or ((not leap) and d < 29)) valid = true;
        }
    }

    return valid;
}
