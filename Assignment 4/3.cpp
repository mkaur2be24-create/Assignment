#include <iostream>
#include <queue>
using namespace std;

void interleaveQueue(queue<int> &q)
{
    int n = q.size();
    queue<int> q1, q2;

    for (int i = 0; i < n / 2; i++)
    {
        q1.push(q.front());
        q.pop();
    }

    for (int i = 0; i < n / 2; i++)
    {
        q2.push(q.front());
        q.pop();
    }

    while (!q1.empty() && !q2.empty())
    {
        q.push(q1.front());
        q1.pop();
        q.push(q2.front());
        q2.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    return 0;
}
