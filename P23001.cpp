#include <iostream>
using namespace std;

int main () 
{
    string first;
    cin >> first;

    int subsequence = 1;
    int resultat = 1;

    string word;
    while (cin >> word) {
        if (word == first) ++subsequence;
        else {
            if (resultat < subsequence) resultat = subsequence;
            subsequence = 0;
        }
    }

    cout << resultat << endl;
}