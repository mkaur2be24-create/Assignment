#include <iostream>
using namespace std;
void sort(int arr[],int n)
{
    int temp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
int main()
{
    cout << "Enter the number of elements in array" << endl;
    int n,num,temp;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,n);
    cout << "Sorted array: ";
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}