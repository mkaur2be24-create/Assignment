#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "Enter size of array: " << endl;
    cin >> n;

    int arr[n];
    cout << "Enter " << n <<" elements:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                count++;
                cout << "(" << arr[i] << "," << arr[j] << ")" << endl;
            }
        }
    }

   cout << "Total number of inversions = " <<  count;
    return 0;
}