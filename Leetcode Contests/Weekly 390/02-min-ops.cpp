#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minOperations(int k)
{
    vector<int> nums = {1}; // Initial array
    int operations = 0;
    int sum = 0;

    for (int num : nums)
        sum += num;

    while (sum < k)
    {
        int max_elem = *max_element(nums.begin(), nums.end()); // Find the maximum element
        if (sum + max_elem <= k)
        {
            nums.push_back(max_elem); // Duplicate the maximum element
            sum += max_elem;
        }
        else
        {
            *max_element(nums.begin(), nums.end()) += 1; // Increase the maximum element
            sum += 1;
        }
        operations++; // Increment the operations count
    }

    return operations;
}

int main()
{
    int k = 11;
    cout << minOperations(k); // Output: 5
    return 0;
}
