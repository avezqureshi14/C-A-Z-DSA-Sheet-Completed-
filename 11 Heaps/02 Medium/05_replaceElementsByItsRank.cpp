#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int N)
{
    vector<int>ans;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < N; i++)
    {
        minHeap.push(arr[i]);
    }
    map<int,int>mp;
    int count = 1;
    while (!minHeap.empty())
    {
        int top = minHeap.top();
        if (mp.find(top) == mp.end())
        {
            mp[top] = count++;
        }
        minHeap.pop();
    }
    for (int i = 0; i < N; i++)
    {
        ans.push_back(mp[arr[i]]);
    }
    
    return ans;
}
int main()
{
    vector<int>arr = {20,15,20,20,26,2,98,6};
    int N = arr.size();
    for(auto i : replaceWithRank(arr,N)){
        cout<<i<<" ";
    }

    return 0;
}