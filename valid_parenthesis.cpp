#include "../myStack.h"
#include<string>

int main() {
	string exp;
	cout << "Enter the Expression : ";
	getline(cin, exp);

	myStack<char> obj(exp.length());

	for (int i = 0; exp[i] != '\0'; i++) { 
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
			obj.push(exp[i]);
		}
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
			if (exp[i] == ')' && obj.top() == '(') {obj.pop();}
			if (exp[i] == '}' && obj.top() == '{') {obj.pop();}
			if (exp[i] == ']' && obj.top() == '[') { obj.pop(); }
		}
	}
	if (obj.isEmpty()) { 
		cout << "valid" << endl;
	}
	else {
		cout << "invalid" << endl;
	}
}