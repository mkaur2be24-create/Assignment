#include <iostream>
#include <string>
using namespace std;

int compare(string s1, string s2)
{
    int i = 0;
    while (i < s1.length() && i < s2.length())
    {
        char c1 = tolower(s1[i]);
        char c2 = tolower(s2[i]);
        if (c1 != c2)
            return (c1 > c2) ? 1 : 0;
        i++;
    }
    return (s1.length() > s2.length()) ? 1 : 0;
}

int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    string arr[n];
    cout << "Enter " << n << " strings:" << endl;
    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (compare(arr[j], arr[j + 1]) == 1)
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    cout << "Strings in alphabetical order:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }

    return 0;
}