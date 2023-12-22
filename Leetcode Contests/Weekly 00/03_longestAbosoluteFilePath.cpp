#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lengthLongestPath(string input)
{
    int n = input.length();
    int count = 0;
    int maxCount = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (input[i] == '.')
        {
            maxCount = max(count, maxCount);
            count = 0;
        }
        if (input[i] == 'n' || input[i] == 't')
        {
            count--;
        }

        count++;
    }
    return maxCount;
}
int main()
{
    string input = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext";
    cout << lengthLongestPath(input);
    // cout<<input.length();
    return 0;
}