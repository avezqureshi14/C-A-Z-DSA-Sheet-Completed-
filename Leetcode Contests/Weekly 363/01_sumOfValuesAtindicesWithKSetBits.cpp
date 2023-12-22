#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int decToBinary(int n)
{
    // Initialize binary array with all zeros
    int binaryNum[32] = {0};

    // Counter for binary array
    int i = 0;
    while (n > 0)
    {
        // Storing remainder in binary
        // array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Convert binary array to decimal integer
    int ans = 0;
    for (int j = i - 1; j >= 0; j--)
    {
        ans = ans * 10 + binaryNum[j];
    }
    return ans;
}


int count1s(int n)
{
    int count = 0;
    while (n != 0)
    {
        int digit = n % 10;
        if (digit == 1)
        {
            count++;
        }
        n = n / 10;
    }
    return count;
}

int sumIndicesWithKSetBits(vector<int> &nums, int k)
{
    int n = nums.size();
    int sum = 0;
    vector<int>setBits;
    
    for (int i = 0; i < n; i++)
    {
        setBits.push_back(count1s(decToBinary(i)));
    }
    
    for (int i = 0; i < n; i++)
    {
        if (setBits[i] == k)
        {
            sum = sum + nums[i];
        }
    }
    
    return sum;
}

int main()
{
    vector<int>nums = {5,10,1,5,2};
    int k = 1;
    cout<<sumIndicesWithKSetBits(nums,k);
    return 0;
}