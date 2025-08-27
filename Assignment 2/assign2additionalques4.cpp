#include <iostream>
using namespace std;

void sort(int arr[], int n)
{
    int left = 0, right = n - 1;

    for (int i = 0; i <= right; i++)
    {
        if (arr[i] == 0)
        {
            int temp = arr[i];
            arr[i] = arr[left];
            arr[left] = temp;
            left++;
        }
    }

    for (int i = right; i >= left; i--)
    {
        if (arr[i] == 2)
        {
            int temp = arr[i];
            arr[i] = arr[right];
            arr[right] = temp;
            right--;
        }
    }
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements (0, 1, 2 only): ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    sort(arr, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}