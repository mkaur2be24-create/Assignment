#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    string str;
    cout << "Enter the string" << endl;
    getline(cin,str);

    stack <char> s;
    for(int i=0;i<str.length();i++)
    {
        s.push(str[i]);
    }

    string rev="";
    while(!s.empty())
    {
        rev+=s.top();
        s.pop();
    }
    cout << "Reversed String: "<< rev << endl;
    return 0;
}