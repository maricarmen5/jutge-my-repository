#include "treeOfSums.hpp"

void treeOfSums_aux(BinaryTree<int>& t)
{
    // Fita: alçada de t
    if ((not t.getLeft().isEmpty()) and (not t.getRight().isEmpty())) {
        // HI: els fills són arbres de sumes
        treeOfSums_aux(t.getLeft()); 
        treeOfSums_aux(t.getRight()); 

        t.getRoot() += t.getLeft().getRoot() + t.getRight().getRoot();
    }
    else if (not t.getLeft().isEmpty()) {
        // HI: el fill esquerre és un arbre de sumes
        treeOfSums_aux(t.getLeft());
        t.getRoot() += t.getLeft().getRoot();
    }
    else if (not t.getRight().isEmpty()) {
        // HI: el fill dret és un arbre de sumes
        treeOfSums_aux(t.getRight());
        t.getRoot() += t.getRight().getRoot();
    }
}

BinaryTree<int> treeOfSums(BinaryTree<int> t) 
{
    treeOfSums_aux(t);
    return t;
}