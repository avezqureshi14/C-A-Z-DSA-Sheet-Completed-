#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long maximumHappinessSum(vector<int> &happiness, int k)
{
    sort(happiness.begin(), happiness.end());
    int n = happiness.size();
    int count = 0;
    int maxH = 0;
    for (int i = 0; i < k; i++)
    {
        int adder = happiness[n - i - 1] - count;
        if (adder > 0)
        {
            maxH = maxH + adder;
        }
        count++;
    }
    return maxH;
}
int main()
{
    vector<int> happiness = {2, 3, 4, 5};
    int k = 1;
    cout << maximumHappinessSum(happiness, k);
    return 0;
}