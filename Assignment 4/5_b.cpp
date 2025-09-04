#include <iostream>
#include <queue>
using namespace std;
class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        for (int i = 0; i < q.size() - 1; i++)
        {
            q.push(q.front());
            q.pop();
        }
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    void top()
    {
        if (q.empty())
        {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top: " << q.front() << endl;
    }
};
