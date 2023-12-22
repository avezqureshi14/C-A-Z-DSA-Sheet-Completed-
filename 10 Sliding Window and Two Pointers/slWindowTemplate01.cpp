#include <iostream>
#include <vector>
using namespace std;

void slidingWindowTemplate(vector<int>& nums, int target) {
    int left = 0, right = 0;
    // Initialize any additional variables needed for the problem
    
    while (right < nums.size()) {
        // Expand the window to the right
        // Update any variables based on the new element
        
        while (/* Check for valid condition based on problem */) {
            // Update the answer or perform necessary operations
            
            // Contract the window from the left
            // Update any variables based on the removed element
            
            left++;
        }
        
        // Move the right pointer to expand the window
        right++;
    }
}

int main() {
    vector<int> nums = /* Initialize your array */;
    int target = /* Set your target value or condition */;

    slidingWindowTemplate(nums, target);

    return 0;
}
