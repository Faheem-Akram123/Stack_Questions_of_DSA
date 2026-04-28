#include "../DSA-headerFiles-using-Cpp/myStack.h"
#include <string>

int main()
{
    string exp;
    cout << "Enter the Expression : ";
    getline(cin, exp);

    myStack<char> obj(exp.length());
    int count = 0;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(')
        {
            obj.push(exp[i]);
        }
        else if (exp[i] == ')' && !obj.isEmpty())
        {
            obj.pop();
            count += 2;
        }
    }
    cout << "Length of longest valid parenthesis: " << count << endl;
}