#include "sumOfValues.hpp"

int sumOfValues(Item *pitem)
{
    int answer = 0;
    if (pitem != NULL) answer = pitem->value + sumOfValues(pitem->next);
    return answer;
}