#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "BinaryTree.hpp"
using namespace std;

void subsequences(BinaryTree<int>& t, vector<int>& sequence, int index, int& answer)
{
    if (not t.isEmpty()) {
        if (index < sequence.size() and sequence[index] == t.getRoot()) ++index;

        if (t.getLeft().isEmpty() and t.getRight().isEmpty()) {
            if (index == sequence.size()) ++answer;
        }
        else {
            subsequences(t.getLeft(), sequence, index, answer);
            subsequences(t.getRight(), sequence, index, answer);
        }
    }
}

int main ()
{
    string tstring;
    cin >> tstring;
    BinaryTree<int> t;
    readStringTree(tstring, t);
    cin.ignore();
    
    string line;
    while (getline(cin, line)) {
        istringstream ss(line);

        vector<int> sequence;
        int x;
        while (ss >> x) sequence.push_back(x);

        int answer = 0;
        subsequences(t, sequence, 0, answer);

        cout << answer << endl; 
    }
}