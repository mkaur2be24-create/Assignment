#include <iostream>
using namespace std;

int main()
{
    char exp[50];
    int stack[50];
    int top = -1;
    int i, a, b;

    cout << "Enter postfix expression: ";
    cin >> exp;

    for (i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            stack[++top] = exp[i] - '0';
        }
        else
        {
            b = stack[top--];
            a = stack[top--];
            if (exp[i] == '+')
                stack[++top] = a + b;
            else if (exp[i] == '-')
                stack[++top] = a - b;
            else if (exp[i] == '*')
                stack[++top] = a * b;
            else if (exp[i] == '/')
                stack[++top] = a / b;
        }
    }

    cout << "Result = " << stack[top] << endl;

    return 0;
}