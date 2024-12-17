#include "pilaFibonacci.hpp"

bool pilaFibonacci_aux(stack<int>& p, int size)
{
	bool ans = true;
	
	if (0 < size) {
		int top = p.top();
		p.pop();
		
		if (size == 1 or size == 2) {
			if (top == 1) ans = pilaFibonacci_aux(p, size - 1);
			else ans = false;
		}
		else {
			bool condition = pilaFibonacci_aux(p, size - 1);
			
			int pre_top = p.top();
			p.pop();
			
			if ((not condition) or (top != pre_top + p.top())) ans = false;
			
			p.push(pre_top);
		}
		
		p.push(top);
	}
	
	return ans;
}

bool pilaFibonacci(stack<int> P)
{
	int size = P.size();
	bool ans = pilaFibonacci_aux(P, size);
	return ans;
}
