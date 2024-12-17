#include "evaluate.hpp"
#include "utils.hpp"

int evaluate(const BinaryTree<string> &t)
{
  int ans = 0;
  
  if (not t.isEmpty()) {
    string s = t.getRoot();
    
    if (isNumber(s)) ans = mystoi(s);
    else {
      int ansLeft = evaluate(t.getLeft());
      int ansRight = evaluate(t.getRight());

      if (s[0] == '+') ans = ansLeft + ansRight;
      else if (s[0] == '-') ans = ansLeft - ansRight;
      else ans = ansLeft * ansRight;
    }
  }
  
  return ans;
}