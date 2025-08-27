#include <iostream>
using namespace std;

int main()
{
    int A[100][3], B[100][3], B_T[100][3], result[100][3];
    int n1, n2, k = 0;

    cout << "Enter number of non-zero elements in Matrix A:\n";
    cin >> n1;
    cout << "Enter triplets (row col val) for Matrix A:\n";
    for (int i = 0; i < n1; i++)
    {
        cin >> A[i][0] >> A[i][1] >> A[i][2];
    }

    cout << "Enter number of non-zero elements in Matrix B:\n";
    cin >> n2;
    cout << "Enter triplets (row col val) for Matrix B:\n";
    for (int i = 0; i < n2; i++)
    {
        cin >> B[i][0] >> B[i][1] >> B[i][2];
    }

    for (int i = 0; i < n2; i++)
    {
        B_T[i][0] = B[i][1];
        B_T[i][1] = B[i][0];
        B_T[i][2] = B[i][2];
    }

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (A[i][1] == B_T[j][1])
            {
                int r = A[i][0];
                int c = B_T[j][0];
                int val = A[i][2] * B_T[j][2];

                bool found = false;
                for (int x = 0; x < k; x++)
                {
                    if (result[x][0] == r && result[x][1] == c)
                    {
                        result[x][2] += val;
                        found = true;
                        break;
                    }
                }

                if (!found)
                {
                    result[k][0] = r;
                    result[k][1] = c;
                    result[k][2] = val;
                    k++;
                }
            }
        }
    }

    cout << "Result of multiplication:\n";
    for (int i = 0; i < k; i++)
    {
        cout << result[i][0] << " " << result[i][1] << " " << result[i][2] << "\n";
    }

    return 0;
}