#include <iostream>
#include "BinaryTree.hpp"
#include "sumOfTree.hpp"
#include <queue>
using namespace std;

int sumOfTree(BinaryTree<int> t)
{
    int ans = 0;
    
    queue< BinaryTree<int> > q;
    q.push(t);
    
    while (not q.empty()) {
       BinaryTree<int> s = q.front();
       q.pop();
       ans += s.getRoot();
       
       if (not s.getLeft().isEmpty()) q.push(s.getLeft());
       if (not s.getRight().isEmpty()) q.push(s.getRight());
    }
    
    return ans;
}