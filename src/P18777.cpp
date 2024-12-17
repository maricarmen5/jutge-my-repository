#include <string>
using namespace std;

string day_of_the_week(int d, int m, int y)
{
    m -= 2;
    if (m < 1) {
        m += 12;
        --y;
    }

    int c = y/100;
    int a = y%100;

    int f = 2.6*m - 0.2;
    f += d + a + a/4 + c/4 - 2*c;
    while (f < 0) f += 7;
    f %= 7;

    string ans = " ";
    switch (f)
    {
        case 0: ans = "Sunday";
        case 1: ans = "Monday";
        case 2: ans = "Tuesday";
        case 3: ans = "Wednesday";
        case 4: ans = "Thursday";
        case 5: ans = "Friday";
        default: ans = "Saturday";
    }

    return ans;
}

int main () {}