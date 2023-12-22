//agar mid element odd hai toh toh left meh reh sakta duplicate mid ko ek left lo, confirm karne ke liye check karo apna next element current element ke similar hai kya 
// 🔥agar same hai toh nahi right meh present hai element 
// 🔥agar nahi hai toh left meh hi check karo right ko mid position par bulao

//agar mid element even hai toh right meh reh sakta duplicate
// 🔥agar same hai toh  right meh confirm present hai element 
// 🔥agar nahi hai toh left meh check karo right ko mid position par bulao

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int singleOneElement(vector<int>&nums){
    int n = nums.size();
    int left = 0;
    int right = n - 1;

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if(mid % 2 == 1){
            mid--;
        }
        if (nums[mid] != nums[mid+1])
        {
            right = mid;
        }
        else{
            left = mid + 2;
        }
        
    }
    return nums[left];
}

int main()
{
    vector<int>nums = {1,1,2,2,3,4,4};
    cout<<"The single element is "<<singleOneElement(nums);
    return 0;
}