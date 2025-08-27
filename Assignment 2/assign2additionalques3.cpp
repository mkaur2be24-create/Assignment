#include <iostream>
#include <string>
using namespace std;

void sort(string s)
{
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (s[j] > s[j + 1])
            {
                char temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}

int anagrams(string str1, string str2)
{
    if (str1.length() != str2.length())
    {
        return 0; 
    }

    sort(str1);
    sort(str2);

    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] != str2[i])
        {
            return 0; 
        }
    }
    return 1; 
}

int main()
{
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    int result = anagrams(str1, str2);

    if (result == 1)
        cout << "Yes, the strings are anagrams\n";
    else
        cout << "No, the strings are not anagrams\n";

    return 0;
}
