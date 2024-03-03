#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isPossibleToSplit(vector<int> &nums)
{
    set<int> st;
    int n = nums.size();
    for (int i = 0; i <= n / 2; i++)
    {
        st.insert(nums[i]);
    }
    for (auto i : st)
    {
        cout << i << " ";
    }
    if (st.size() != n / 2)
    {
        return false;
    }
    cout << endl;
    st.clear();
    for (int i = n / 2; i < n; i++)
    {
        st.insert(nums[i]);
    }
    for (auto i : st)
    {
        cout << i << " ";
    }
    if (st.size() != n / 2)
    {
        return false;
    }
    else
    {
        return true;
    }
}
int main()
{
    vector<int> nums = {1, 1, 2, 2, 3, 4};
    bool ans = isPossibleToSplit(nums);
    cout << ans;
    return 0;
}