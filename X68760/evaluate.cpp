#include "evaluate.hpp"
#include "utils.hpp"

int evaluate(map<string,int> &variable2value, const BinaryTree<string> &t)
{
  int ans = 0;
  
  if (not t.isEmpty()) {
    string s = t.getRoot();
    
    if (isNumber(s)) ans = mystoi(s);
    else if (isVariable(s)) ans = variable2value[s];
    else {
      int ansLeft = evaluate(variable2value, t.getLeft());
      int ansRight = evaluate(variable2value, t.getRight());

      if (s[0] == '+') ans = ansLeft + ansRight;
      else if (s[0] == '-') ans = ansLeft - ansRight;
      else ans = ansLeft * ansRight;
    }
  }
  
  return ans;
}