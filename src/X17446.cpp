#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

void SumBelowLeap2_aux(stack<int>& s, int size)
{
    if (2 < size) {
        int top = s.top();
        s.pop();

        SumBelowLeap2_aux(s, size - 1);
        // HI: s conté a les posicions parelles (senars) la suma dels 
        // enters anteriors a posicions parelles (senars) menys al cim
        // Fita: s.size()

        int pre_top = s.top();
        s.pop();
        top += s.top();

        s.push(pre_top);
        s.push(top);
    }
}

stack<int> SumBelowLeap2(stack<int> s)
{
    int size = s.size();
    SumBelowLeap2_aux(s, size);
    return s;
}

int main () {}