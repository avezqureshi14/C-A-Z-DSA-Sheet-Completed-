#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareByFirstTwoElements(const vector<int> &offer1, const vector<int> &offer2)
{
    if (offer1[0] != offer2[0])
    {
        return offer1[0] < offer2[0];
    }
    return offer1[1] < offer2[1];
}

int maximizeTheProfit(int n, vector<vector<int>> &offers)
{
    int maxProfit = 0;
    sort(offers.begin(), offers.end(), compareByFirstTwoElements);
    for (int i = 0; i < n - 1; i++)
    {
        if (offers[i][1] < offers[i + 1][0])
        {
            maxProfit = max(maxProfit, offers[i][2] + offers[i + 1][2]);
        }
    }
    return maxProfit;
}

int main()
{
    vector<vector<int>> offers = {{0, 0, 1}, {0, 0, 2}, {1, 3, 2}};
    int n = offers.size();
    cout << maximizeTheProfit(n, offers);
    return 0;
}
