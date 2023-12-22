#include <iostream>
#include <vector>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int maxLen = 0;
    int zeroCount = 0;
    int left = 0;

    for (int right = 0; right < nums.size(); right++)
    {
        if (nums[right] == 0)
        {
            zeroCount++;
        }

        while (zeroCount > k)
        {
            if (nums[left] == 0)
            {
                zeroCount--;
            }
            left++;
        }

        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 1};
    int k = 3;
    cout << longestOnes(nums, k);

    return 0;
}
