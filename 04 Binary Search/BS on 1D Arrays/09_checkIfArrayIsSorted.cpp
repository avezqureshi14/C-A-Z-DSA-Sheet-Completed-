#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSorted(vector<int>nums){
    int n = nums.size();
    for (int i = 0; i < n-1; i++)
    {
        //🔥 while checking element is sorted remember to stop on step before 
        if (nums[i] > nums[i+1])
        {
            return false;
        }
        
    }
    return true;
}
int main()
{
    vector<int>nums={90, 100, 200, 400, 500, 600, 700, 900};
    if (isSorted(nums))
    {
        cout<<"Sorted"<<endl;
    }
    else{
        cout<<"Not Sorted"<<endl;

    }
    
    return 0;
}