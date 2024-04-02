#include <iostream>
#include <list>
using namespace std;

void move_it_mid(int size, list<int>& l, list<int>::iterator& it_mid, int& elements_at_front, int& elements_at_back, string instruction)
{
    if (size == 1) {
        it_mid = l.begin();
        elements_at_front = 0;
        elements_at_back = 0;
    }
    else {
        if ((instruction == "push_front") or (instruction == "pop_back")) {
            if (instruction == "push_front") ++elements_at_front;
            else --elements_at_back;

            if ((size % 2 != 0) and (elements_at_back < elements_at_front)) {
                --it_mid;
                --elements_at_front;
                ++elements_at_back;
            }
        }
        else {
            if (instruction == "push_back") ++elements_at_back;
            else --elements_at_front;

            if ((size % 2 != 0) and (elements_at_front < elements_at_back)) {
                ++it_mid;
                ++elements_at_front;
                --elements_at_back;
            }
        }
    }
}

int main () 
{
    list<int> l;
    list<int>::iterator it_mid;
    int size = 0;
    int elements_at_front = 0;
    int elements_at_back = 0;

    string instruction;
    while (cin >> instruction) {
        if ((instruction == "push_front") or (instruction == "push_back")) {
            int x;
            cin >> x;

            if (instruction == "push_front") l.push_front(x);
            else l.push_back(x);
            ++size;

            move_it_mid(size, l, it_mid, elements_at_front, elements_at_back, instruction);
        }
        else if ((instruction == "pop_front") or (instruction == "pop_back")) {
            if (size == 0) cout << "error" << endl;
            else {
                if (instruction == "pop_front") l.pop_front();
                else l.pop_back();
                --size;
                
                move_it_mid(size, l, it_mid, elements_at_front, elements_at_back, instruction);
            }
        }
        else {
            if (size % 2 == 0) cout << "error" << endl;
            else cout << *it_mid << endl;
        }
    }
}