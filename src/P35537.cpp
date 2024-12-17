#include <iostream>
#include <vector>
using namespace std;

bool es_creixent(int n) 
{
    bool trobat;
    if (n < 10) trobat = true;
    else {
        int a = n%10;
        int b = (n%100)/10;
        if (b <= a) trobat = es_creixent(n/10);
        else trobat = false;
    }
  
    return trobat;
}
