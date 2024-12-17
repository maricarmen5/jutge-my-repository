#include "equilibriSenarParell.hpp"

int equilibriSenarParell_aux(const BinaryTree<int>& t)
{
    int diferencia = 0;

    if (not t.isEmpty()) {
        if (t.getRoot()%2 == 0) ++diferencia;
        else --diferencia;

        int difEsq = equilibriSenarParell_aux(t.getLeft());

        if (abs(difEsq) <= 1) {
            int difDre = equilibriSenarParell_aux(t.getRight());

            if (abs(difDre) <= 1) diferencia += difEsq + difDre;
            else diferencia = difDre;
        }
        else diferencia = difEsq;
    }

    return diferencia;
}

bool equilibriSenarParell(const BinaryTree<int> &t)
{
    bool resposta = false;
    if (abs(equilibriSenarParell_aux(t)) <= 1) resposta = true;
    return resposta;
}