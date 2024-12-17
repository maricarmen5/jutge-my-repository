#include "copy.hpp"

Item* copy(Item* pitem)
{
    Item* p = NULL;

    if (pitem != NULL) {
        p = new Item;
        p->value = pitem->value;
        p->next = copy(pitem->next);
    }

    return p;
}