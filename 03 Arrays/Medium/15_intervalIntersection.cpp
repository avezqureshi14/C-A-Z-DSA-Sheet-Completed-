#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
{
    vector<vector<int>> ans;
    int n1 = firstList.size();
    int n2 = secondList.size();
    int i = 0;
    int j = 0;
    while (i < n1 && j < n2)
    {
        int left = max(firstList[i][0], secondList[j][0]);
        int right = min(firstList[i][1], secondList[j][1]);
        if (left <= right)
        {
            ans.push_back({left, right});
        }
        if (firstList[i][1] > secondList[j][1])
        {
            j++; // agar niche wala second element chota hai toh aur comparison ho sakte
        }
        else
        {
            i++;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> firstList = {{1, 3}, {5, 9}, {13, 23}, {24, 25}};
    vector<vector<int>> secondList = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
    for (auto i : intervalIntersection(firstList, secondList))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}