#include <iostream>
#include <vector>
#include <numeric> // For std::gcd
using namespace std;

int countSubarraysWithLCM(vector<int> &nums, int k)
{
    int count = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        for (int j = i; j < n && temp <= k; j++)
        {
            temp = lcm(temp, nums[j]);
            if (temp == k)
            {
                count++;
            }
        }
    }
    return count;
}

int main()
{
    vector<int> nums = {3};
    int k = 2;
    cout << countSubarraysWithLCM(nums, k) << endl; // Output: 9
    return 0;
}
