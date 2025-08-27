#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter value of k: ";
    cin >> k;

    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((arr[i] - arr[j]) == k || (arr[i] - arr[j]) == -k)
            {
                count++;
                cout << "(" << arr[i] << ", " << arr[j] << ")\n";
            }
        }
    }

    cout << "Total pairs with difference " << k << " = " << count << endl;
    return 0;
}