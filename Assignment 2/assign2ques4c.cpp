#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str,final="";
    char ch;
    cout << "Enter the string: ";
    getline(cin, str);
    int n=str.length();
    for(int i=0;i<n;i++)
    {
        ch=tolower(str[i]);
        if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u')
        {
            final+=str[i];
        }
    }
    cout << "Reversed string: " << final << endl;
    return 0;
}