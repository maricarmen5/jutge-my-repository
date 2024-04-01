#include "maxOfTree.hpp"

int maxOfTree_aux(BinaryTree<int>& t)
{
    int ans = t.getRoot();
    int a;

    // Fita: alçada de t, quan t no tingui fills no es farà crida recursiva

    if (not t.getLeft().isEmpty()) {
        // HI: a = màxim del subarbre fill esquerra de t
        a = maxOfTree_aux(t.getLeft());
        if (ans < a) ans = a;
    }

    if (not t.getRight().isEmpty()) {
        // HI: a = màxim del subarbre fill dret de t
        a = maxOfTree_aux(t.getRight());
        if (ans < a) ans = a;
    }

    return ans;
}

int maxOfTree(BinaryTree<int> t)
{
    int ans = maxOfTree_aux(t);
    return ans;
}