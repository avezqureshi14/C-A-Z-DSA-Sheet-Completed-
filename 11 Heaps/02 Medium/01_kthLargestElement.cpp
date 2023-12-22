#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(nums[i]);
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }
    return minHeap.top();
}
int main()
{
    vector<int>nums = {3,2,3,1,2,4,5,5,6};
    int k = 4;
    cout<<findKthLargest(nums,k);
    return 0;
}