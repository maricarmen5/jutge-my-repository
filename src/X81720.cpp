#include <iostream>
using namespace std;

bool wellBracketed_aux(const string& s, int i, int closedMinusOpen)
{
    bool ans = true;

    if (0 <= i) {
        if (s[i] == ')') closedMinusOpen += 1;
        else closedMinusOpen -= 1;

        if (closedMinusOpen < 0) ans = false;
        else ans = wellBracketed_aux(s, i - 1, closedMinusOpen);
    }
    else if (closedMinusOpen != 0) ans = false;

    return ans;
}

bool wellBracketed(string s)
{
    int closedMinusOpen = 0;
    int i = s.length() - 1;
    bool ans = wellBracketed_aux(s, i, closedMinusOpen);
    return ans;
}
