#include <iostream>
#include <string>
#include <stack>
#include <sstream>
using namespace std;

stack<int> intercal_aux(stack<int>& s1, stack<int>& s2)
{
    stack<int> ans;

    if (not s1.empty()) {
        if (s2.size() < s1.size()) {
            int top = s1.top();
            s1.pop();
            ans = intercal_aux(s1, s2);
            ans.push(top);
        }
        else {
            int top1 = s1.top();
            int top2 = s2.top();

            s1.pop();
            s2.pop();

            ans = intercal_aux(s1, s2);

            ans.push(top1);
            ans.push(top2);
        }
    }

    return ans;
}

// Pre:  Siguin [a1,a2,...,an] i [b1,b2,...,bm] els valors inicials de s1 i s2, respectivament.
// Post: En el cas n>=m, la pila retornada és [a1,b1,a2,b2,...,am,bm,a{m+1},a{m+2},...,an].
//       En el cas n<m, la pila retornada és [b1,a1,b2,a2,...,bn,an,b{n+1},b{n+2},...,bm].
stack<int> intercal(stack<int> s1, stack<int> s2)
{
    stack<int> ans;
    if (s1.size() < s2.size()) ans = intercal_aux(s2, s1);
    else ans = intercal_aux(s1, s2);
    return ans;
}

int main () {}