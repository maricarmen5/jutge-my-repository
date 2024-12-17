#include "copyEvenPos.hpp"

Item* copyEvenPos(Item* pitem)
{
    Item* p = NULL;

    if (pitem != NULL) {
        p = new Item;
        p->value = pitem->value;
        p->next = NULL;
        
        if (pitem->next != NULL) {
            p->next = copyEvenPos(pitem->next->next);
        }
    }

    return p;
}