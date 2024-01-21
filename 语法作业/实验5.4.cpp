/*逆波兰表示法（Reverse Polish Notation，RPN，或逆波兰记法），是一种是由波兰逻辑学家 J. Lukasiewicz于1929年提出的数学表达式的方法。
  在逆波兰记法中，所有操作符置于操作数的后面，因此也被称为后缀表示法。逆波兰记法不需要括号来标识操作符的优先级。
  例如：1 + 2 * (3 - 4) - 5 * 6的后缀表达式为1 2 3 4 - * + 5 6 * -
  假设表达式中只包含变量（变量名只由小写字母构成）和加、减、乘、除四种运算，并且乘、除运算符的优先级高于加、减，请设计函数 
  void transfer(char* source, char* target)，实现将表达式转换成逆波兰记法。
  【输入格式】
  一个表达式，仅包含变量、加减乘除四种运算符，并且变量名只由小写字母构成
  【输出格式】
  该表达式的逆波兰记法
  【输入样例】
  a+b*c-d+f/e
  【输出样例】
  abc*+d-fe/+*/
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isOperator(char c) {
	return c == '+' || c == '-' || c == '*' || c == '/';
}

int getPriority(char c) {
	if (c == '*' || c == '/') {
		return 2;
	} else if (c == '+' || c == '-') {
		return 1;
	}
	return 0;
}

void transfer(char* source, char* target) {
	stack<char> operators;
	
	int i = 0;
	int j = 0;
	
	while (source[i] != '\0')
	{
		if (isalpha(source[i])) 
		{
			target[j++] = source[i++];
		}
		else if (isOperator(source[i])) 
		{
			while (!operators.empty() && operators.top() != '(' && getPriority(source[i]) <= getPriority(operators.top())) 
			{
				target[j++] = operators.top();
				operators.pop();
			}
			operators.push(source[i++]);
		} 
		else if (source[i] == '(') 
		{
			operators.push(source[i++]);
		}
		else if (source[i] == ')') 
		{
			while (!operators.empty() && operators.top() != '(') 
			{
				target[j++] = operators.top();
				operators.pop();
			}
			if (!operators.empty() && operators.top() == '(') 
			{
				operators.pop();
			}
			i++;
		}
	}
	
	while (!operators.empty()) 
	{
		target[j++] = operators.top();
		operators.pop();
	}
	
	target[j] = '\0';
}

int main() 
{
	char source[100];
	char target[100];
	
	cin >> source;
	
	transfer(source, target);
	
	cout << target << endl;
	
	return 0;
}

