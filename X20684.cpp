#include <iostream>
#include <list>
using namespace std;

void update_list(list<int>& l, int code, double& sum, double& size, int n)
{
    bool found = false;
    list<int>::iterator it = l.begin();
    while ((not found) and it != l.end()) {
        if (n <= *it) found = true; 
        else ++it;
    } // it: position of n in list

    if (code == -1)
    {
        if (found) l.insert(it, n);
        else l.push_back(n);
        ++size;
        sum += (double)n;
    }
    else if (found and n == *it) // n found in list
    {
        it = l.erase(it); // n removed
        --size;
        sum -= (double)n;
    } 
}

int main ()
{
    list<int> l;
    double sum = 0.0;
    double size = 0.0;

    int code, n;
    cin >> code >> n;
    while (code != 0)
    {
        update_list(l, code, sum, size, n);

        if (l.empty()) cout << 0 << endl;
        else 
        {
            list<int>::iterator extrem = l.begin();
            cout << *extrem << ' '; // min
                
            extrem = l.end(), --extrem;
            cout << *extrem << ' '; // max

            cout << sum/size << endl; // average
        }

        cin >> code >> n;
    }
}