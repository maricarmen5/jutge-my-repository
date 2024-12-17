#include "merge.hpp"

Item* merge(Item* pitem1, Item* pitem2)
{
    Item* p = NULL;

    if ((pitem1 != NULL) and (pitem2 != NULL)) {
        p = new Item;
        
        if (pitem1->value < pitem2->value) {
            p->value = pitem1->value;
            p->next = merge(pitem1->next, pitem2);
        } 
        else {
            p->value = pitem2->value;
            p->next = merge(pitem1, pitem2->next);
        }
    }
    else if (pitem1 != NULL) {
        p = new Item;

        p->value = pitem1->value;
        p->next = merge(pitem1->next, pitem2);
    }
    else if (pitem2 != NULL) {
        p = new Item;

        p->value = pitem2->value;
        p->next = merge(pitem1, pitem2->next);
    }

    return p;
}