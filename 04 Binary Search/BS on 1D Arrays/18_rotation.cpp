#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int numberOfRotationI(vector<int>arr){
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i+1])
        {
            return i + 1;
        }
        
    }
    return 0;
}

int numberOfRotation(vector<int>arr){
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    while (low < high)
    {
        int mid = low + (high-low) / 2;
        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else{
            high = mid;
        }
    }

    return low;
}
int main()
{
    vector<int>arr = {1,2,3,4,5};
    cout<<"The given array is rotated by "<<numberOfRotation(arr);
    return 0;
}