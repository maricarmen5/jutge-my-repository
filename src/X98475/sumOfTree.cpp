#include <iostream>
#include "BinaryTree.hpp"
#include "sumOfTree.hpp"
using namespace std;

int sumOfTree_aux(BinaryTree<int>& t)
{
    int ans = 0;

    if (not t.isEmpty()) {
        ans = t.getRoot() + sumOfTree_aux(t.getLeft()) + sumOfTree_aux(t.getRight());
    }
    
    return ans;
}

int sumOfTree(BinaryTree<int> t)
{
    int ans = sumOfTree_aux(t);
    return ans;
}