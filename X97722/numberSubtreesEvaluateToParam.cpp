#include "numberSubtreesEvaluateToParam.hpp"
#include "utils.hpp"

// Fita: t.height()
int numberSubtreesEvaluateToParam_aux(const BinaryTree<string> &t, int x, int& evaluate)
{
	int answer = 0;	
	string s = t.getRoot();

	if (isNumber(s)) {
		evaluate = mystoi(s);
		if (x == evaluate) answer = 1;
	}
	else {
		answer = numberSubtreesEvaluateToParam_aux(t.getLeft(), x, evaluate);
		// HI: answer is the number of repetitions of x in evaluate of t.getLeft()
		
		int result = 0;
		answer += numberSubtreesEvaluateToParam_aux(t.getRight(), x, result);
		// HI: answer is the number of repetitions of x in evaluate of t.getRight()
		
		if (s[0] == '+') evaluate += result;
		else if (s[0] == '-') evaluate -= result;
		else evaluate *= result;
		
		if (x == evaluate) answer += 1;
	}
	
	return answer;
}

int numberSubtreesEvaluateToParam(const BinaryTree<string> &t, int x)
{
	
	int evaluate = 0;
	int answer = numberSubtreesEvaluateToParam_aux(t, x, evaluate);
	return answer;
}