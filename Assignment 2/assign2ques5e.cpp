#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int sym[10];

    cout << "Enter " << n * (n + 1) / 2 << " elements of symmetric matrix \n";
    for (int i = 0; i < n * (n + 1) / 2; i++)
    {
        cin >> sym[i];
    }

    cout << "Symmetric Matrix:\n";
    int k = 0;

    int mat[4][4];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            mat[i][j] = sym[k++];
            mat[j][i] = mat[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}