#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isNStraightHand(vector<int> &hand, int groupSize)
{
    int n = hand.size();
    sort(hand.begin(),hand.end());
    unordered_map<int,int>mp;
    for(auto i : hand){
        mp[i]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (mp[hand[i]] == 0)
        {
            continue;
        }
        for (int j = 0; j < groupSize; j++)
        {
            int currCard = hand[i] + j;
            if (mp[currCard] == 0)
            {
                return false;
            }
            mp[currCard]--;
        }
    }
    return true;
}
int main()
{
    vector<int>hand = {1,2,3,4,5};
    int groupSize = 4;
    cout<<isNStraightHand(hand,groupSize);
    return 0;
}