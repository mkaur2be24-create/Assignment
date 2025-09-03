#include <iostream>
#include <stack>
using namespace std;

#define MAX 1000

bool Stack(int A[], int n)
{
    stack<int> s;
    int B[MAX];
    int bIndex = 0;

    int sorted[MAX];
    for (int i = 0; i < n; i++)
    {
        sorted[i] = A[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (sorted[j] > sorted[j + 1])
            {
                int temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    int sortedIndex = 0;
    int i = 0;
    while (i < n)
    {
        s.push(A[i]);
        i++;
        while (!s.empty() && s.top() == sorted[sortedIndex])
        {
            B[bIndex++] = s.top();
            s.pop();
            sortedIndex++;
        }
    }
    return (bIndex == n);
}

int main()
{
    int n;
    cout << "Enter size of array A: ";
    cin >> n;

    int A[MAX];
    cout << "Enter elements of array A: ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    if (Stack(A, n))
    {
        cout << "Yes, B can be sorted using these operations" << endl;
    }
    else
    {
        cout << "No, B cannot be sorted using these operations" << endl;
    }
    return 0;
}
