#include <iostream>
using namespace std;

bool is_palindromic(int n) 
{
   int aux = n;
   int copy = 0;
   while (aux != 0) {
      int digit = aux%10;
      copy = (copy*10) + digit;
      aux = aux/10;
   }

   bool answer = false;
   if (copy == n) answer = true;
   
   return answer;
}

int main () {}