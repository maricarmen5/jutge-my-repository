#include "push_back.hpp"

void push_back(Item* pitem, int value)
{
    if (pitem->next == NULL) {
        pitem->next = new Item;
        pitem->next->value = value;
        pitem->next->next = NULL;
    }
    else push_back(pitem->next, value);
}