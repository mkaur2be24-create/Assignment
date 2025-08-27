#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int lower[10];

    cout << "Enter " << n * (n + 1) / 2 << " elements of lower triangular matrix:\n";
    for (int i = 0; i < n * (n + 1) / 2; i++)
    {
        cin >> lower[i];
    }

    cout << "Lower Triangular Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                cout << lower[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}