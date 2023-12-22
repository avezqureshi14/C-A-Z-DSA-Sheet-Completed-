#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int nonDup(vector<int>nums){
    int xOr = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        int prev = xOr;
        xOr = xOr ^ nums[i];
        cout<<"array ele "<<nums[i]<<" xor with "<<prev<<" gives "<<xOr<<endl;
    }

    return xOr;
}
int main()
{
    //couples gets killed single are saved 
    vector<int>nums = {1,2,2,3,4,4,3,5,5,9,9};
    cout<<nonDup(nums);
    return 0;
}