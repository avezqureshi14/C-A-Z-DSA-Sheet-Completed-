#include <bits/stdc++.h>
using namespace std;

vector<int> ansOfTwoaArrays(vector<int> nums1, vector<int> nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n1 && j < n2)
    {
        if (nums1[i] <= nums2[j]) // Case 1 and 2
        {
            if (ans.size() == 0 || ans.back() != nums1[i])
                ans.push_back(nums1[i]);
            i++;
        }
        else // case 3
        {
            if (ans.size() == 0 || ans.back() != nums2[j])
                ans.push_back(nums2[j]);
            j++;
        }
    }
    while (i < n1) // IF any element left in nums1
    {
        if (ans.back() != nums1[i])
            ans.push_back(nums1[i]);
        i++;
    }
    while (j < n2) // If any elements left in nums2
    {
        if (ans.back() != nums2[j])
            ans.push_back(nums2[j]);
        j++;
    }
    return ans;
}

int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 5};
    vector<int> nums2 = {2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6};

    for (auto i : ansOfTwoaArrays(nums1, nums2))
    {
        cout << i << " ";
    }

    return 0;
}
