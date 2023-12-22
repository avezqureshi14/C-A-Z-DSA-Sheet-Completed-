#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> countSort(vector<int> nums) {
    int maxi = 0;
    int n = nums.size();
    
    // Find the maximum value in the input vector
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, nums[i]);
    }
    
    // Create a count array and initialize it with zeros
    vector<int> count(maxi + 1, 0);
    
    // Count the occurrences of each element
    for (int i = 0; i < n; i++) {
        count[nums[i]]++;
    }
    
    // Calculate the cumulative count
    for (int i = 1; i <= maxi; i++) {
        count[i] += count[i - 1];
    }
    
    // Create the output vector with the same size as the input
    vector<int> ans(n);
    
    // Fill the output vector by placing elements in their sorted order
    for (int i = n - 1; i >= 0; i--) {
        ans[count[nums[i]] - 1] = nums[i];
        count[nums[i]]--;
    }
    
    return ans;
}

int main() {
    vector<int> nums = {4, 3, 12, 1, 5, 5, 3, 9};
    vector<int> sorted_nums = countSort(nums);
    for (auto i : sorted_nums) {
        cout << i << " ";
    }
    return 0;
}
