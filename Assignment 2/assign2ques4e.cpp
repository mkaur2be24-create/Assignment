#include <iostream>
#include <string>
using namespace std;
char toLowerCase(char c)
{
    if(c>='A' && c<='Z')
        return c+32;
    return c;
}
int main()
{
    char c;
    cout << "Enter the uppercase character: ";
    cin >> c;
    cout << "After converting to Lower Case: " << toLowerCase(c);
}