#include <iostream>
using namespace std;
int main()
{
    int arr[3][3] = {1,2,3,4,5,6,7,8,9}, brr[3][3] = {2,3,4,3,4,5,4,5,6},c[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            c[i][j]=0;
            for(int k=0;k<3;k++)
            {
                c[i][j]+=arr[i][k]*brr[k][j];
            }
        }
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}