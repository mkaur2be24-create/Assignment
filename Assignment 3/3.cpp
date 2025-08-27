#include <iostream>
#include <string>
#include <stack>
using namespace std;
class parentheses
{
public:
    bool isValid(string s)
    {
        stack<char> str;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
                str.push(s[i]);
            else if (str.empty())
                return false;
            else if (s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                char ch = str.top();
                if (s[i] == ')' && ch == '(')
                    str.pop();
                else if (s[i] == ']' && ch == '[')
                    str.pop();
                else if (s[i] == '}' && ch == '{')
                    str.pop();
                else
                    return false;
            }
        }
        if (str.empty())
            return true;
        else
            return false;
    }
};
int main()
{
    parentheses x;
    string s;
    cout << "Enter the string of Parentheses" << endl;
    cin >> s;
    if(x.isValid(s))
        cout << "Valid Parentheses" << endl;
    else
        cout << "Invalid Parentheses" << endl;
    return 0;
}