#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>
using namespace std;

void replace0sWithBelowSumPosEven_aux(stack<int>& s, int pos, int& sumPosEven)
{
    if (-1 < pos) {
        int top = s.top();
        s.pop();

        replace0sWithBelowSumPosEven_aux(s, pos - 1, sumPosEven);
        // HI: s conté a les posicions on hi havia un 0 la suma dels 
        // anteriors enters a posicions parelles, menys al cim.
        // Fita: s.size()

        if (pos % 2 == 0) sumPosEven += top;

        if (top == 0) s.push(sumPosEven);
        else s.push(top);
    }
}

stack<int> replace0sWithBelowSumPosEven(stack<int> s)
{
    int pos = s.size() - 1;
    int sumPosEven = 0;
    replace0sWithBelowSumPosEven_aux(s, pos, sumPosEven);
    return s;
}