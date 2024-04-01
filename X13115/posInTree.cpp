#include "posInTree.hpp"

void posInTree_aux(BinaryTree<int>& t, int x, list<int>& ans) 
{
	if (t.getRoot() == x) ans.push_front(t.getRoot());
    else {
        if (not t.getLeft().isEmpty()) posInTree_aux(t.getLeft(), x, ans);
        if (ans.empty() and (not t.getRight().isEmpty())) posInTree_aux(t.getRight(), x, ans);
        if (not ans.empty()) ans.push_front(t.getRoot());
    }
}

list<int> posInTree(const BinaryTree<int> t, int x)
{
    list<int> ans;
    BinaryTree<int> t_aux = t;
    posInTree_aux(t_aux, x, ans);
    return ans;
}