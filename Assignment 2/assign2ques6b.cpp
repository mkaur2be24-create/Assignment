#include <iostream>
using namespace std;

int main()
{
    int A[100][3], B[100][3], result[200][3];
    int n1, n2;

    cout << "Enter number of non-zero elements in matrix A:\n";
    cin >> n1;
    cout << "Enter triplets (row col value) for A:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    cout << "Enter number of non-zero elements in matrix B:\n";
    cin >> n2;
    cout << "Enter triplets (row col value) for B:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (A[i][0] == B[j][0] && A[i][1] == B[j][1])
        {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2] + B[j][2];
            i++;
            j++;
            k++;
        }
        else if (A[i][0] < B[j][0] || (A[i][0] == B[j][0] && A[i][1] < B[j][1]))
        {
            result[k][0] = A[i][0];
            result[k][1] = A[i][1];
            result[k][2] = A[i][2];
            i++;
            k++;
        }
        else
        {
            result[k][0] = B[j][0];
            result[k][1] = B[j][1];
            result[k][2] = B[j][2];
            j++;
            k++;
        }
    }

    while (i < n1)
    {
        result[k][0] = A[i][0];
        result[k][1] = A[i][1];
        result[k][2] = A[i][2];
        i++;
        k++;
    }

    while (j < n2)
    {
        result[k][0] = B[j][0];
        result[k][1] = B[j][1];
        result[k][2] = B[j][2];
        j++;
        k++;
    }

    cout << "Result of addition:\n";
    for (int x = 0; x < k; x++)
    {
        cout << result[x][0] << " " << result[x][1] << " " << result[x][2] << "\n";
    }

    return 0;
}