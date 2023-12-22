#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int buyAndSellStock(vector<int> prices)
{
    int n = prices.size();
    int maxProfit = 0;
    int maxValue = prices[0];
    int minValue = prices[0];

    for (int i = 1; i < n; i++)
    {
        if (prices[i] < minValue)
        {
            minValue = prices[i];
            maxValue = prices[i];
        }
        else if (prices[i] > maxValue)
        {
            maxValue = prices[i];
            int tempProfit = maxValue - minValue;
            maxProfit = max(maxProfit, tempProfit);
        }
    }

    return maxProfit;
}

int main()
{
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit Earned can be by Buying and Selling the Stock is " << buyAndSellStock(nums) << endl;
    return 0;
}