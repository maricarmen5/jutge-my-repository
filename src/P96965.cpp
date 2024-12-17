#include <iostream>
using namespace std;

int reduccio_digits(int x) 
{
    int resp = 0;
    if (9 < x) {
        while (0 < x) {
            resp += x%10;
            x /= 10;
        }
        resp = reduccio_digits(resp);
    } 
    else resp = x;
  
    return resp;
}
