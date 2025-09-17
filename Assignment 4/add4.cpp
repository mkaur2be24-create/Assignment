#include <iostream>
#include <queue>
using namespace std;

int countStudents(int students[], int studentsSize, int sandwiches[], int sandwichesSize)
{
    queue<int> q;
    for (int i = 0; i < studentsSize; i++)
        q.push(students[i]);

    int index = 0, count = 0;

    while (!q.empty() && count < q.size())
    {
        if (q.front() == sandwiches[index])
        {
            q.pop();
            index++;
            count = 0;
        }
        else
        {
            q.push(q.front());
            q.pop();
            count++;
        }
    }
    return q.size();
}

int main()
{
    int students[] = {1, 1, 0, 0};
    int sandwiches[] = {0, 1, 0, 1};
    int studentsSize = sizeof(students) / sizeof(students[0]);
    int sandwichesSize = sizeof(sandwiches) / sizeof(sandwiches[0]);

    cout << countStudents(students, studentsSize, sandwiches, sandwichesSize) << endl;

    return 0;
}
