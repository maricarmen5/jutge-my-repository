#include <iostream>
using namespace std;

bool is_perfect(int x) 
{
    bool answer = true;

    int i = 2;
    while (answer and i*i <= x) {
        if (x%i == 0) answer = false;
        ++i;
    }
    if (x == 0 or x == 1) answer = false;

    return answer;
}

int main() {}