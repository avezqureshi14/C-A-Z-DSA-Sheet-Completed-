#include <iostream>
#include <sstream>
using namespace std;

string reverseWords(string s)
{
    int n = s.length();
    string substring;
    string result;
    int i = 0;
    while (i < n)
    {
        while (i < n && s[i] == ' ')
        {
            i++;
        }
        if (i >= n)
        {
            break;
        }
        int j = i + 1;
        while (j < n && s[j] != ' ')
        {
            j++;
        }
        substring = s.substr(i, j - i);
        if (result.length() == 0)
        {
            result = substring;
        }
        else
        {
            result = substring + " " + result;
        }
        i = j + 1;
    }

    return result;
}

int main()
{
    string s = "The sky is blue";
    string reversedString = reverseWords(s);
    cout << reversedString << endl;
    return 0;
}
