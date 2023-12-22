#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumOperationsII(string num)
{
    int n = num.length();
    int count = 0;
    string check = "";
    for (int i = n - 1; i >= 0; i--)
    {
        long long n = stoi(num);
        if (n % 25 == 0)
        {
            return count;
        }
        num.pop_back();
        count++;
    }
    return count;
}

int solveRecur(string num, int n, int count, int minCount)
{
    if (n == 0)
    {
        return minCount;
    }

    // Check if the current string can be made divisible by 25
    if (stoi(num) % 25 == 0)
    {
        minCount = min(count, minCount);
    }

    // Try two recursive paths: removing the last digit or keeping it
    return min(solveRecur(num.substr(0, n - 1), n - 1, count + 1, minCount),  // Remove last digit
               solveRecur(num, n - 1, count, minCount));                    // Keep last digit
}

int minimumOperations(string num)
{
    int n = num.size();
    int count = 0;
    int minCount = 1000;
    return solveRecur(num, n, count, minCount);
}

int main()
{
    string nums = "2908305";
    cout << minimumOperations(nums);
    return 0;
}