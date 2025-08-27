#include <iostream>
using namespace std;
int main()
{
    int rows, cols;
    int arr[10][10];

    cout << "Enter number of rows and columns: " << endl;
    cin >> rows >> cols;

    cout << "Enter elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
    {
        int rowSum = 0;
        for (int j = 0; j < cols; j++)
        {
            rowSum += arr[i][j];
        }
        cout << "Sum of Row " << i + 1 << " = " << rowSum << endl;
    }

    for (int j = 0; j < cols; j++)
    {
        int colSum = 0;
        for (int i = 0; i < rows; i++)
        {
            colSum += arr[i][j];
        }
        cout << "Sum of Column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}