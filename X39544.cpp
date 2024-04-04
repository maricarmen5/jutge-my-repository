#include <iostream>
#include <stack>
using namespace std;

void SumParellSenar_aux(stack<int>& s, int& sumParell, int& sumSenar)
{
    if (not s.empty()) {
        int top = s.top();
        s.pop();

        SumParellSenar_aux(s, sumParell, sumSenar);

        if (top%2 == 0) {
            sumParell += top;
            s.push(sumParell);
        }
        else {
            sumSenar += top;
            s.push(sumSenar);
        }
    }  
}

stack<int> SumParellSenar(stack<int> s)
{
    int sumParell = 0;
    int sumSenar = 0;
    SumParellSenar_aux(s, sumParell, sumSenar);
    return s;
}

int main() {}
