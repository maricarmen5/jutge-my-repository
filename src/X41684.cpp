#include <iostream>
#include <list>
using namespace std;

void update_frequency(list<int>& l, list<int>& frequency, int x, string instruction)
{
    if (l.empty()) {
        if (instruction == "push_back" or instruction == "push_front") frequency.push_back(1);
        else frequency.pop_back();
    }
    else {
        list<int>::iterator it;
        list<int>::iterator it_frequency;

        if (instruction == "push_back" or instruction == "pop_back") {
            it = l.end(), --it;
            it_frequency = frequency.end(), --it_frequency;
        }
        else {
            it = l.begin();
            it_frequency = frequency.begin();
        }

        if (x == *it) {
            if (instruction == "push_back" or instruction == "push_front") ++*it_frequency;
            else --*it_frequency;
        }
        else if (instruction == "push_back") frequency.push_back(1);
        else if (instruction == "push_front") frequency.push_front(1);
        else if (instruction == "pop_back") frequency.pop_back();
        else frequency.pop_front();
    }
}

int main ()
{
    list<int> l;
    list<int> frequency;

    string instruction;
    while (cin >> instruction) {
        int x;

        if (instruction == "pop_back" or instruction == "pop_front") {
            if (l.size() == 0) cout << "error" << endl;
            else {
                if (instruction == "pop_back") {
                    x = l.back();
                    l.pop_back();
                }
                else {
                    x = l.front();
                    l.pop_front();
                }

                update_frequency(l, frequency, x, instruction);
            }
        }
        else if (instruction == "push_back" or instruction == "push_front") {
            cin >> x;

            update_frequency(l, frequency, x, instruction);

            if (instruction == "push_back") l.push_back(x);
            else l.push_front(x);
        }
        else {
            if (frequency.empty()) cout << 0 << endl;
            else if (instruction == "max_equal_left") cout << frequency.front() << endl;
            else cout << frequency.back() << endl;
        }
    }
}
