#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> productExceptSelf(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans;
    int totalProd = 1;
    int zero = 0;
    for (auto i : nums)
    {
        if (i == 0)
        {
            zero++;
        }
        if (zero > 1 || i != 0)
        {
            totalProd = totalProd * i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            ans.push_back(totalProd);
        }
        else
        {
            if (zero == 0)
            {
                int val = totalProd / nums[i];
                ans.push_back(val);
            }
            else
            {
                ans.push_back(0);
            }
        }
    }
    return ans;
}

vector<int> productExceptSelfII(vector<int> nums)
{
    int n = nums.size();
    vector<int> prefix(n, 1); // Initialize a prefix product array.
    vector<int> suffix(n, 1); // Initialize a suffix product array.
    vector<int> result(n);

    // Calculate prefix products.
    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] * nums[i - 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << prefix[i]<<" ";
    }
    cout << endl;

    // Calculate suffix products.
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = suffix[i + 1] * nums[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        cout << suffix[i]<<" ";
    }
    cout << endl;

    // Calculate the final result using prefix and suffix products.
    for (int i = 0; i < n; i++)
    {
        result[i] = prefix[i] * suffix[i];
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    for (auto i : productExceptSelfII(nums))
    {
        cout << i << " ";
    }
    return 0;
}