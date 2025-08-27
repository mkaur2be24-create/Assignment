#include <iostream>
using namespace std;
void linear_search(int arr[],int n,int num)
{
    int c=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            cout << "Element found at index " << i << endl;
            c++;
        }
    }
    if(c==0)
        cout<<"Element not found" << endl;
}
int main()
{
    int n=7;
    int arr[n] = {1,2,3,4,5,6,7};
    int num;
    cout << "Enter the number to be searched" << endl;
    cin >> num;
    linear_search(arr,n,num);
    return 0;
}