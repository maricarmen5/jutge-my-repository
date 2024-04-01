#include "heightOfTree.hpp"

int heightOfTree_aux(BinaryTree<int>& t)
{
    int ans = 0;

    if (not t.isEmpty()) {
        // HI: heightOfTree_aux(t.getLeft()) = alçada del fill esquerra de t
        // i heightOfTree_aux(t.getRight()) = alçada del fill dret de t
        // Fita: alçada de t = {0 (t buit), 1 + alçada del fill més gran (quan t no és buit)} 
        ans = 1 + max(heightOfTree_aux(t.getLeft()), heightOfTree_aux(t.getRight()));
    }

    return ans;
}

int heightOfTree(BinaryTree<int> t)
{
    int ans = heightOfTree_aux(t);
    return ans;
}