#include "sumAtDepthEven.hpp"

int sumAtDepthEven_aux(BinaryTree<int>& t, int level)
{
    int ans = 0;
    
    if (not t.isEmpty()) {
        if (level % 2 == 0) ans = t.getRoot();

        // HI: ans = suma d'elements a nivell parell del 
        // fill esquerra + suma d'elemets a nivell parell 
        // del fill dret + arrel de t (si el nivell és 
        // parell)
        // Fita: alçada de t = {0 (t és buit), 1 + alçada del fill més gran (quan t no és buit)}
        ans += sumAtDepthEven_aux(t.getLeft(), level + 1);
        ans += sumAtDepthEven_aux(t.getRight(), level + 1);
    }

    return ans;
}

// Pre:
// Post: Retorna la suma dels valors de t a profunditat parell
int sumAtDepthEven(BinaryTree<int> t)
{
    int level = 0;
    int ans = sumAtDepthEven_aux(t, level);
    return ans;
}