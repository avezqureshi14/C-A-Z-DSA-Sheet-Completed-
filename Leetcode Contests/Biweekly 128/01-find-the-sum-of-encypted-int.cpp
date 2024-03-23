#include <iostream>
#include <bits/stdc++.h>
using namespace std;

pair<int, int> largestandCountDigit(int num)
{
    // get last number
    pair<int, int> p;
    int maxDigit = num % 10;
    int count = 0;

    while (num > 0)
    {
        int digit = num % 10;
        count++;
        if (digit > maxDigit)
        {
            maxDigit = digit;
        }
        num = num / 10;
    }
    p = {maxDigit, count};
    return p;
}

int concatenateNum(int num, int count)
{
    string numStr1 = to_string(num);
    string result = "";
    for (int i = 0; i < count; i++)
    {
        result = result + numStr1;
    }
    return stoi(result);
}

int sumOfEncryptedInt(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> p = largestandCountDigit(nums[i]);
        int maxDigit = p.first;
        int count = p.second;
        ans = ans + concatenateNum(maxDigit, count);
    }

    return ans;
}
int main()
{
    vector<int> nums = {19, 21, 31};
    cout << sumOfEncryptedInt(nums);
    return 0;
}