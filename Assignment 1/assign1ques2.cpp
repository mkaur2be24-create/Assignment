#include <iostream>
using namespace std;
int main()
{
    cout << "Enter the number of elements" << endl;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter " << n <<" elements" << endl;
    for(int i=0;i<n;i++)
    {
        cin >>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j])
            {
                for(int k=j;k<n-1;k++)
                {
                    arr[k]=arr[k+1];
                }
                n--;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}