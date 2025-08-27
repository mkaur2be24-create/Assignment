#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;

    cout << "Enter the string: ";
    getline(cin, str);
    int n=str.length();
    int i=0,j=n-1;
    char temp;
    while(i<j)
    {
        temp=str[j];
        str[j]=str[i];
        str[i]=temp;
        i++;
        j--;
    }

    cout << "Reveresed String: " << str << endl;
    return 0;
}