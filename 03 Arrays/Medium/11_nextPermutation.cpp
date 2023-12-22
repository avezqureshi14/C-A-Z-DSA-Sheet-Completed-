#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> nextGreaterPermutation(vector<int> &nums)
{
    int n = nums.size();

    // Step 1: find the break point
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // if the break point does not exist
    if (ind == -1)
    {
        reverse(nums.begin(), nums.end());
        return nums;
    }

    // Step 2: Find the next greater element and swap it with nums[ind]
    for (int i = n - 1; i > ind; i--)
    {
        if (nums[i] > nums[ind])
        {
            swap(nums[i], nums[ind]);
            break;
        }
    }

    // Step 3: Reverse the right half
    reverse(nums.begin() + ind + 1, nums.end());
    return nums;
}

int main()
{
    vector<int> nums = {1,2,3};
    vector<int> ans = nextGreaterPermutation(nums);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}
