#include "maximumTree.hpp"

// Post: els nodes de ans contenen el màmix dels nodes de 
// t1 o t2 (si un és buit pren el valor del node no buit)
// que són a la mateixa posició
void maximumTree_aux(BinaryTree<int>& t1, BinaryTree<int>& t2, BinaryTree<int>& ans)
{
    if ((not t1.isEmpty()) and (not t2.isEmpty())) {
        int root = t1.getRoot();
        if (root < t2.getRoot()) root = t2.getRoot();

        ans = BinaryTree<int>(root, BinaryTree<int>(), BinaryTree<int>());

        maximumTree_aux(t1.getLeft(), t2.getLeft(), ans.getLeft());  
        maximumTree_aux(t1.getRight(), t2.getRight(), ans.getRight()); 
        // HI: els nodes del fill esquerre (dret) d'ans 
        // contenen el màxim dels nodes del fill esquerre 
        // (dret) de t1 i t2 (si un node és buit pren el 
        // valor del node ple) que són a la mateixa posició
        // Fita: max(alçada de t1 i t2) 
    }
    else if (not t1.isEmpty()) {
        ans = BinaryTree<int>(t1.getRoot(), BinaryTree<int>(), BinaryTree<int>());

        maximumTree_aux(t1.getLeft(), t2, ans.getLeft()); 
        maximumTree_aux(t1.getRight(), t2, ans.getRight()); 
        // HI: el fill esquerre (dret) d'ans és igual al 
        // fill esqerre (dret) de t1
        // Fita: alçada de t1
    }
    else if (not t2.isEmpty()) {
        ans = BinaryTree<int>(t2.getRoot(), BinaryTree<int>(), BinaryTree<int>());

        maximumTree_aux(t1, t2.getLeft(), ans.getLeft()); 
        maximumTree_aux(t1, t2.getRight(), ans.getRight()); 
        // HI: el fill esquerre (dret) d'ans és igual al 
        // fill esqerre (dret) de t2
        // Fita: alçada de t2
    }
}

BinaryTree<int> maximumTree(BinaryTree<int> t1,BinaryTree<int> t2)
{
    BinaryTree<int> ans;
    maximumTree_aux(t1, t2, ans);
    return ans;
}