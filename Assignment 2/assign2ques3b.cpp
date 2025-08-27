#include <iostream>
using namespace std;
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
    int n=7;
    int arr[n] = {1,2,3,4,5,6,7};
    int num;
    cout << "Enter the number to be searched" << endl;
    cin >> num;
    binary_search(arr,n,num);
    return 0;
}