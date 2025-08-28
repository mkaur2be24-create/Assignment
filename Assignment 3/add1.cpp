#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
        cin >> A[i];
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && s.top() >= A[i])
            s.pop();
        if (s.empty())
            cout << -1 << " ";
        else
            cout << s.top() << " ";
        s.push(A[i]);
    }
    return 0;
}