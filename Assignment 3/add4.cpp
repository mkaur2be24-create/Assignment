#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int temp[n], ans[n];
    for (int i = 0; i < n; i++)
        cin >> temp[i];
    stack<int> s;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!s.empty() && temp[s.top()] <= temp[i])
            s.pop();
        if (s.empty())
            ans[i] = 0;
        else
            ans[i] = s.top() - i;
        s.push(i);
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
    return 0;
}