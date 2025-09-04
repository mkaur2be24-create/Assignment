#include <iostream>
#include <queue>
using namespace std;

class Stack
{
    queue<int> q1, q2;
public:
    void push(int x)
    {
        q1.push(x);
    }

    void pop()
    {
        if (q1.empty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        while (q1.size() > 1)
        {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        swap(q1, q2);
    }

    void top()
    {
        if (q1.empty())
        {
            cout << "Stack is Empty\n";
            return;
        }
        cout << "Top: " << q1.back() << endl;
    }
};
