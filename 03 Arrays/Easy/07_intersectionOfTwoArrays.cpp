#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//this code will be taking O(N) time complexity for finding intersection of the element
vector<int> intersectionOfTwoArrays(vector<int>nums1, vector<int>nums2){
    vector<int>ans;
    int i, j = 0;
    int n = nums1.size();
    int m = nums2.size();
    while (i < n && j < m)
    {
        if (nums1[i] == nums2[j])
        {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j]){
            i++;
        }
        else if(nums1[i] > nums2[j]){
            j++;
        }
    }

    return ans;
}
int main()
{
    vector<int>nums1 = {1,1,2,3,4,5};
    vector<int>nums2 = {1,2,3,6,7,8};
    for(auto i : intersectionOfTwoArrays(nums1,nums2)){
        cout<<i<<" ";
    }
    return 0;
}