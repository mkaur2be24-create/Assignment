#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the number of elements" << endl;
    int n,temp;
    cin >> n;
    int arr[n];
    cout << "Enter " << n <<" elements" << endl;
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
    }
    for(int i=0;i<n/2;i++)
    {
        temp = arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}