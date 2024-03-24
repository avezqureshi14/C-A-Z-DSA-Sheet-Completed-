#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool canChange(string start, string target)
{
    int n = start.size();
    int i = 0;
    int j = 0;
    while (i < n || j < n)
    {
        while (i < n && start[i] == '_')
        {
            i++;
        }
        while (j < n && target[j] == '_')
        {
            j++;
        }
        if (i == n || j == n)
        {
            break;
        }
        if (start[i] == target[j])
        {
            if (start[i] == 'L' && i < j)
            {
                return false;
            }
            else if (start[i] == 'R' && i > j)
            {
                return false;
            }
        }
        else
        {
            return false;
        }
        i++;
        j++;
    }
    return i == n && j == n;
}

int main()
{
    string start = "_L__R__R_";
    string target = "L______RR";
    cout << canChange(start, target);
    return 0;
}
