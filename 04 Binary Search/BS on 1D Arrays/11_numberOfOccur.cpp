#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int firstPos(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
    }
    return ans;
}
int lastPos(vector<int> &arr, int target)
{
    int n = arr.size();
    int low = 0;
    int high = n - 1;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > target)
        {
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
    }
    return ans;
}

int count(vector<int> &arr, int target)
{
    int first = firstPos(arr, target);
    //this is very much important line, please dont forget this 
    if (first == -1) //if first is -1 the element is not present in the array
    {
        return 0;
    }
    int last = lastPos(arr,target);
    return last - first + 1;
}

int main()
{
    vector<int> arr = {1,3,4};
    cout << "The number of occurences are " << count(arr, 3) << endl;

 
    return 0;
} 