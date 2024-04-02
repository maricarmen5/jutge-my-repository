#include <iostream>
using namespace std;

int main () 
{
    int sequences;
    cin >> sequences;
    
    int s = 0;
    while (s < sequences) {
        int pairs = 0;

        int first;
        cin >> first;
        while (first != 0) {  
            int second;  
            cin >> second;

            if (first < second) ++pairs;
            first = second;
        }

        cout << pairs << endl;
        ++s;
    }
}