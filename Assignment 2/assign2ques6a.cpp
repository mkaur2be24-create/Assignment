#include <iostream>
using namespace std;

int main()
{
    int sparse[100][3];
    int transpose[100][3];

    int rows, cols, nonZero;

    cout << "Enter rows, columns, and number of non-zero elements:\n";
    cin >> rows >> cols >> nonZero;

    cout << "Enter the triplets (row col value):\n";
    for (int i = 0; i < nonZero; i++)
    {
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
    }

    for (int i = 0; i < nonZero; i++)
    {
        transpose[i][0] = sparse[i][1];
        transpose[i][1] = sparse[i][0];
        transpose[i][2] = sparse[i][2];
    }

    cout << "Transposed triplets:\n";
    for (int i = 0; i < nonZero; i++)
    {
        cout << transpose[i][0] << " " << transpose[i][1] << " " << transpose[i][2] << "\n";
    }

    return 0;
}