#include "sumOfValuesEvenPosition.hpp"

int sumOfValuesEvenPosition(Item *pitem)
{
    int answer = 0;

    if (pitem != NULL) {
        answer = pitem->value;

        if (pitem->next != NULL) {
            answer += sumOfValuesEvenPosition(pitem->next->next);
        }     
    }

    return answer;
}