#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int squareOfNum(int n){
    return n*n;
}

vector<int>squaresOfArray(vector<int>nums){
    vector<int>ans;
    for(auto i : nums){
        ans.push_back(squareOfNum(i));
    }
    sort(ans.begin(),ans.end());
    return ans;
}

vector<int> sortedSquaresII(vector<int>& nums) {
    transform(nums.begin(), nums.end(), nums.begin(), [](int n) { return n * n; });
    sort(nums.begin(), nums.end());
    return nums;
}


int main()
{
    vector<int>nums  = {-4,-1,0,3,10};
    for(auto i : squaresOfArray(nums)){
        cout<<i<<" ";
    }
    
    return 0;
}