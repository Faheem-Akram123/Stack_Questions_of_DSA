#include "../myStack.h"
#include <string>

int applyOp(const int &a, const int &b, const char &op)
{
	if (op == '+')
		return a + b;
	if (op == '-')
		return a - b;
	if (op == '/')
		return a / b;
	if (op == '*')
		return a * b;
}

int presedence(const char &op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	else if (op == '/' || op == '*')
	{
		return 2;
	}
	return 0;
}

int main()
{
	string exp;
	cout << "Enter expression : ";
	getline(cin, exp);

	myStack<int> values(exp.length());
	myStack<char> ops(exp.length());

	for (int i = 0; exp[i] != '\0'; i++)
	{
		if (exp[i] == ' ')
		{
			continue;
		}
		else if (exp[i] == '(')
		{
			ops.push(exp[i]);
		}
		else if (exp[i] >= '0' && exp[i] <= '9')
		{
			int val = 0;
			while (i < exp.length() && exp[i] >= '0' && exp[i] <= '9')
			{
				val = val * 10 + (exp[i] - '0');
				i++;
			}
			values.push(val);
			i--;
		}
		else if (exp[i] == ')')
		{
			while (!ops.isEmpty() && ops.top() != '(')
			{
				values.push(applyOp(values.pop(), values.pop(), ops.pop()));
			}
			ops.pop();
		}
		else
		{
			while (!ops.isEmpty() && presedence(ops.top()) >= presedence(exp[i]))
			{
				values.push(applyOp(values.pop(), values.pop(), ops.pop()));
			}
			ops.push(exp[i]);
		}
	}

	while (!ops.isEmpty())
	{
		values.push(applyOp(values.pop(), values.pop(), ops.pop()));
	}

	cout << "result is : " << values.top() << endl;
}