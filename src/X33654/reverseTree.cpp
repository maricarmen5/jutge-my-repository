#include "reverseTree.hpp"

void reverseTree_aux(BinaryTree<int>& t, BinaryTree<int>& ans)
{
    if (not t.isEmpty()) {
        int root = t.getRoot();

        ans = BinaryTree<int>(root, BinaryTree<int>(), BinaryTree<int>());

        //Fita: alçada de t
        reverseTree_aux(t.getLeft(), ans.getRight());
        //HI: el fill dret de ans és el revessat del fill esquerra de t
        reverseTree_aux(t.getRight(), ans.getLeft());
        //HI: el fill esquerra de ans és el revessat del fill dret de t
    }
}

BinaryTree<int> reverseTree(BinaryTree<int> t)
{
    BinaryTree<int> ans;
    reverseTree_aux(t, ans);
    return ans;
}