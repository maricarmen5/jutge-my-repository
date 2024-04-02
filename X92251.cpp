#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

void sumAboveOrBelow_aux(stack<int>& sint, stack<string>& sstring, int pos, int sum_above, int& sum_below)
{
    if (-1 < pos) {
        int sint_top = sint.top();
        sint.pop();

        string sstring_top = sstring.top();
        sstring.pop();

        sum_above += sint_top;

        sumAboveOrBelow_aux(sint, sstring, pos - 1, sum_above, sum_below);

        sum_below += sint_top;

        if (sstring_top == "above") sint.push(sum_above);
        else sint.push(sum_below);
    }
}

stack<int> sumAboveOrBelow(stack<int> sint, stack<string> sstring)
{
    int pos = sint.size() - 1;
    int sum_above = 0;
    int sum_below = 0;

    sumAboveOrBelow_aux(sint, sstring, pos, sum_above, sum_below);
    return sint;
}

int main () {}