#include <iostream>
#include <queue>
#include <limits.h>
using namespace std;

int minIndex(queue<int> q, int sortedIndex)
{
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();

        if (curr <= min_val && i <= sortedIndex)
        {
            min_val = curr;
            min_index = i;
        }
        q.push(curr);
    }
    return min_index;
}

// Move min element to end
void insertMinToRear(queue<int> &q, int min_index)
{
    int min_val;
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.pop();
        if (i == min_index)
        {
            min_val = curr;
        }
        else
        {
            q.push(curr);
        }
    }
    q.push(min_val);
}

void sortQueue(queue<int> &q)
{
    for (int i = 1; i <= q.size(); i++)
    {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

int main()
{
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    sortQueue(q);

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}