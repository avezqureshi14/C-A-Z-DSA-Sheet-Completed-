#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int>leaders(vector<int>a){
    int n = a.size();
    vector<int>leader;
    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        for (int j = i+1; j < n; j++)
        {
            if (a[i] < a[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            leader.push_back(a[i]);
        }
        
    }

    return leader;
    
}

vector<int>leaderOptimal(vector<int>a){
    int n = a.size();
    vector<int>leader;
    int maxi = INT_MIN;
    for (int i = n-1; i >= 0; i--)
    {
        if (a[i] > maxi)
        {
            leader.push_back(maxi);
        }
        maxi = max(maxi,a[i]);
    }
    reverse(leader.begin(),leader.end());
    return leader;
}

int main()
{
    vector<int>a = {10,22,12,3,0,6};
    for(auto i : leaderOptimal(a)){
        cout<<i<<" ";
    }
    return 0;
}