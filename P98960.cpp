#include <iostream>
using namespace std;

int main ()
{
    char letra;
    cin >> letra;

    if ('a' <= letra and letra <= 'z') letra -= 32;
    else letra += 32;

    cout << letra << endl;
}