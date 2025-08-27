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
void binary_search(int arr[],int n,int num)
{
    int start=0,end=n-1,mid,c=0;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==num)
        {
            cout << num << " found at index "<< mid << endl;
            c++;
            break;
        }
        else if(arr[mid]>num)
        {
            end=mid-1;
        }
        else
        {
            start=mid+1;
        }
    }
    if(c==0)
        cout<< "Element not found" << endl;
}
int main()
{
    cout << "Enter the number of elements in array" << endl;
    int n,num;
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr,n);
    cout << "Enter the number to be searched" << endl;
    cin >> num;
    binary_search(arr,n,num);
    return 0;
}