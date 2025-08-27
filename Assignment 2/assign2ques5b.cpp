#include <iostream>
using namespace std;

int main()
{
    int n = 4;
    int tri[10];

    cout << "Enter " << 3 * n - 2 << " elements of tri-diagonal matrix:\n";
    for (int i = 0; i < 3 * n - 2; i++)
    {
        cin >> tri[i];
    }

    cout << "Tri-diagonal Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - j == 1)
                cout << tri[k++] << " ";
            else if (i == j)
                cout << tri[k++] << " ";
            else if (i - j == -1)
                cout << tri[k++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }

    return 0;
}