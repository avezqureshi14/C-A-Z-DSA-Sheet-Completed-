#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int temp[], int left, int mid, int right)
{
    int i, j, k;
    int inv_count = 0;
    i = left;
    j = mid;
    k = left;
    while ((i <= mid - 1) && (j <= right))
    {
        if (arr[i] <= arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
            cout << "This is j(mid) " << mid << " " << arr[mid] << endl;
            cout << "This is i(left) " << i << " " << arr[i] << endl;
            inv_count = inv_count + (mid - i);
            cout << "Inversion count is " << inv_count << endl;
            cout << endl;
        }
    }

    while (i <= mid - 1)
    {
        temp[k++] = arr[i++];
    }

    while (j <= right)
    {
        temp[k++] = arr[j++];
    }

    for (i = left; i <= right; i++)
    {
        arr[i] = temp[i];
    }

    return inv_count;
}

int mergeSort(int arr[], int temp[], int left, int right)
{
    int mid, inv_count = 0;
    if (right > left)
    {
        mid = (right + left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);

        inv_count += merge(arr, temp, left, mid + 1, right);
    }

    return inv_count;
}

int main()
{
    int arr[] = {2, 4, 3, 5, 1};
    // int arr[] = {2,3,4,5,6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int temp[n];
    int ans = mergeSort(arr, temp, 0, n - 1);
    cout << "Number of inversions are " << ans;
    return 0;
}