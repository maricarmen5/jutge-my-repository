#include <iostream>
using namespace std;

int main () 
{
    char letra;
    cin >> letra;

    if ('a' <= letra and letra <= 'z') cout << "lowercase" << endl;
    else cout << "uppercase" << endl;

    if (letra == 'a' or letra == 'A' or
    letra == 'e' or letra == 'E' or
    letra == 'i' or letra == 'I' or
    letra == 'o' or letra == 'O' or
    letra == 'u' or letra =='U') cout << "vowel" << endl;
    else cout << "consonant" << endl;
}