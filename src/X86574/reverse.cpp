#include "reverse.hpp"

Item* reverse_aux(Item* pitem, Item* p)
{
    if (pitem != NULL) {
        Item* p_aux = new Item;
        p_aux->value = pitem->value;
        p_aux->next = p;

        p = reverse_aux(pitem->next, p_aux);
    }

    return p;
}

Item* reverse(Item* pitem)
{
    Item* p = NULL;
    p = reverse_aux(pitem, p);
    return p;
}