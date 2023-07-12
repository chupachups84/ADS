#include "ClassStack.h"
#include <iostream>
#include <string>
using namespace std;
bool isCorrect(const string& str) {
	TStack<char> stack;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
			stack.push(str[i]);
		else if (str[i] == ')' || str[i] == ']' || str[i] == '}')
			if ( stack.isEmpty() ||
				(stack.peek() == '(') ^ (str[i] == ')') ||
				(stack.peek() == '[') ^ (str[i] == ']') ||
				(stack.peek() == '{') ^ (str[i] == '}' )  )
				return false;
			else
				stack.pop();
	}
	return stack.isEmpty();
}
string inToPost(const string& str) {
	TStack<char> stack;
	string postfixExpr = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			postfixExpr += str[i];
		}
		else if (str[i] == '(') {
			stack.push(str[i]);
		}
		else if (stack.isEmpty() &&
			(str[i] == '+' || str[i] == '*' || str[i] == '-' || str[i] == '/'||stack.peek()=='(')) {
			stack.push(str[i]);
		}
		else if (!stack.isEmpty()
			&& ((stack.peek() == '*' || stack.peek() == '/') && (str[i] == '+' || str[i] == '-') || (stack.peek() == '+' || stack.peek() == '-') && (str[i] == '+' || str[i] == '-'))) {
			while (!stack.isEmpty()||stack.peek() != '(' || stack.peek() != '+' || stack.peek() != '-') {
				postfixExpr += stack.peek();
				stack.pop();
			}
			stack.pop();
		}
		else if (!stack.isEmpty()&&str[i] == ')') {
			while (!stack.isEmpty() || stack.peek() != '(') {
				postfixExpr += stack.peek();
				stack.pop();
			}
			stack.pop();
		}
		else {
			while (!stack.isEmpty()) {
				postfixExpr += stack.peek();
				stack.pop();
			}
		}
	}
	return postfixExpr;
}
void main() {
	string s1 = "5-(3+4*6)/9";
	cout << inToPost(s1);
}