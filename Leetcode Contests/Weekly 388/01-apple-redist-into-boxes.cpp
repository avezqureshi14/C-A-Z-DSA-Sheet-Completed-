#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimumBoxes(vector<int> &apple, vector<int> &capacity)
{
    int appleSum = 0;
    for (int i = 0; i < apple.size(); i++)
    {
        appleSum = appleSum + apple[i];
    }

    int n = capacity.size();
    sort(capacity.begin(), capacity.end());
    int capSum = 0;
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        if (capSum >= appleSum)
        {
            return count;
        }
        capSum += capacity[i];
        count++;
    }
    return count;
}
int main()
{
    vector<int> apple = {1, 3, 2};
    vector<int> capacity = {4, 3, 1, 5, 2};
    cout << minimumBoxes(apple, capacity);
    return 0;
}