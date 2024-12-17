#include <iostream>
#include <sstream>
#include <string>
#include <stack>
using namespace std;

bool palindrom(stack<int> p)
{
    bool ans = true;
    int s = p.size()/2;
    stack<int> paux;

    for (int i = 0; i < s; ++i) {
        paux.push(p.top());
        p.pop();
    }

    if (p.size() != paux.size()) p.pop();

    while ((not p.empty()) and ans) {
        // p and paux have the same elements
        if (p.top() != paux.top()) ans = false;
        p.pop();
        paux.pop();
    }

    return ans;
}

int main () 
{
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);
        stack<int> p;
        int x;
        
        while (ss >> x) p.push(x);

        bool ans = palindrom(p);

        cout << "It is ";
        if (not ans) cout << "NOT ";
        cout << "a palindrome." << endl;
    }
}