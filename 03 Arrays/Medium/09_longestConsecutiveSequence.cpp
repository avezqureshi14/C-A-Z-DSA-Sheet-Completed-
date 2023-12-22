#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int longestConsecutiveSeq(vector<int> nums) {
    unordered_set<int> set;
    for (auto i : nums) {
        set.insert(i);
    }
    int count = 0;
    int maxCount = 0;
    for (auto i : set) {
        int value = i - 1;
        if (set.count(value) == 0) {
            int check = i;
            while (set.count(check) != 0) {
                count++;
                check++;
            }
        }
        maxCount = max(maxCount, count);
        count = 0;
    }
    return maxCount;
}

int main()
{
    vector<int>nums = {100,4,200,1,3,2};
    cout<<"The longest consequtive sequence is of length "<<longestConsecutiveSeq(nums);
    return 0;
}