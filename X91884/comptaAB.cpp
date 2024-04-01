#include "comptaAB.hpp"
// igual al problema X94001

BinaryTree<int> comptaAB_aux(BinaryTree<string>& t, int a, int b, char child)
{
    BinaryTree<int> answer;

    if (not t.isEmpty())
    {
        if (t.getRoot() == "a") ++a;
        else ++b;

        int root = a; // left child
        if (child == 'R') root = b; // right child
        else if (child == 'X') root = 1; // parent root

        BinaryTree<int> left = comptaAB_aux(t.getLeft(), a, b, 'L');
        BinaryTree<int> right = comptaAB_aux(t.getRight(), a, b, 'R');
        answer = BinaryTree<int>(root, left, right);
    }

    return answer;
}

BinaryTree<int> comptaAB(BinaryTree<string> t)
{
    BinaryTree<int> answer = comptaAB_aux(t, 0, 0, 'X');
    return answer;
}