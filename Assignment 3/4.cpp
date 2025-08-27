#include <iostream>
#include <string>
#include <stack>
using namespace std;
class postfix
{
    int priority(char ch)
    {
        if(ch=='^')
            return 3;
        else if(ch=='*' || ch=='/')
            return 2;
        else if(ch=='+' || ch=='-')
            return 1;
        else
            return -1;
    }
public:

    string post(string s)
    {
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
                ans = ans + s[i];
            else if (s[i] == '(')
                st.push(s[i]);
            else if (s[i] == ')')
            {
                while (st.top() != '(')
                {
                    ans = ans + st.top();
                    st.pop();
                }
                st.pop();
            }
            else
            {
                if(st.empty() || priority(s[i])>priority(st.top()))
                    st.push(s[i]);
                else 
                {
                    while(!st.empty() && priority(st.top())>=priority(s[i]))
                    {
                        ans = ans + st.top();
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        while(!st.empty())
        {
            ans = ans + st.top();
            st.pop();
        }
        return ans;
    }
};
int main()
{
    postfix x;
    cout << "Enter the infix expression" << endl;
    string str;
    cin >> str;
    string ans = x.post(str);
    cout << "The Postfix Expresson: " << ans;
    return 0;
}