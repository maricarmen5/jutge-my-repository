#include "replace0sWithAboveSumDepthEven.hpp"

void replace0sWithAboveSumDepthEven_aux(BinaryTree<int>& t, int level, int sum)
{
    if (not t.isEmpty()) {
        if (level % 2 == 0) sum += t.getRoot();
        if (t.getRoot() == 0) t.getRoot() = sum;

        // Fita: alçada de t
        // HI: al fill esuerra (i al dret) de t els zeros són reemplaçats 
        // per la suma dels elements anteriors a nivell parell 
        replace0sWithAboveSumDepthEven_aux(t.getLeft(), level + 1, sum);
        replace0sWithAboveSumDepthEven_aux(t.getRight(), level + 1, sum);   
    }
}

BinaryTree<int> replace0sWithAboveSumDepthEven(BinaryTree<int> t)
{
    int level = 0;
    int sum = 0;

    replace0sWithAboveSumDepthEven_aux(t, level, sum);

    return t;
}