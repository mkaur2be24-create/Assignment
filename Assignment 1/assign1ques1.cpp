#include <iostream>
using namespace std;
int arr[100];
void createarr(int n)
{
    cout << "Enter " << n << " elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}
void display(int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void insert(int n)
{
    cout << "Enter the index where number is to be entered" << endl;
    int idx;
    cin >> idx;
    for (int i = n; i > idx; i--)
    {
        arr[i] = arr[i - 1];
    }
    cout << "Enter the number to be entered" << endl;
    cin >> arr[idx];
}
void del(int n)
{
    cout << "Enter the index of number to be deleted" << endl;
    int idx;
    cin >> idx;
    for(int i=idx;i<n-1;i++)
    {
        arr[i]=arr[i+1];
    }
}
void search(int  n)
{
    cout << "Enter the number to be searched" << endl;
    int num,count=0;
    cin >> num;
    for(int i=0;i<n;i++)
    {
        if(arr[i]==num)
        {
            cout << "Element found at index " << i << endl;
            count++;
        }
    }
    if(count==0)
        cout << "Element not found" << endl;
}
int main()
{

    int ch, n;

    do
    {
        cout << "Enter your choice" << endl;
        cout << "1. Create Array" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Insert an element" << endl;
        cout << "4. Delete an element" << endl;
        cout << "5. Linear Search" << endl;
        cout << "6. EXIT" << endl;
        cin >> ch;

        switch (ch)
        {
        case 1:
            cout << "Enter the size of array" << endl;
            cin >> n;
            createarr(n);
            break;

        case 2:
            display(n);
            break;

        case 3:
            insert(n++);
            break;

        case 4:
            del(n--);
            break;
        
        case 5:
            search(n);
            break;
        case 6:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Wrong Input" << endl;
        }   
    } while (ch != 6);
}