#include <iostream>
#include <vector>
using namespace std;

int main () 
{
    int n;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; ++i) cin >> v[i];

    for (int i = n - 1; 0 <= i; --i) {
        string word = v[i];
        
        int meitat = word.length()/2;
        int mida = word.length() - 1;
        for (int j = 0; j < meitat; ++j) swap(word[j], word[mida - j]);

        cout << word << endl;
    }
}
