#include "evaluateStrings.hpp"

void reverse(string& s, int index_left, int index_right) 
{
    if (index_left < index_right) {
		swap(s[index_left], s[index_right]);
        // Fita: index_right - index_lefts
		reverse(s, index_left + 1, index_right - 1);
        // HI: (s[index_left]...s[index_right]) is reversed
	}
}

string evaluate(const BinaryTree<string> &t)
{
    // Fita: t.height()
    string ans = t.getRoot();
    char leter = ans[0];

    if (leter < 'a') {
        ans = evaluate(t.getLeft());
        // HI: t.getLeft().getRoot() is an evaluated expression

        if (leter == 'R') reverse(ans, 0, (int)ans.size() - 1);
        else ans += evaluate(t.getRight());
        // HI: t.getRight().getRoot() is an evaluated expression
    }

    return ans;
}