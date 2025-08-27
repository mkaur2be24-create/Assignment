#include <iostream>
using namespace std;
void push(int arr[],int n,int i)
{
    for(int j=n-1;j>i+1;j--)
    {
        arr[j]=arr[j-1];
    }
}
void duplicate(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==2)
        {
            push(arr,n,i);
            arr[i+1]=2;
            i++;
        }
    }
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    duplicate(arr,n);
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}