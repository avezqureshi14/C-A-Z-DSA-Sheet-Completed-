#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// funtion to print array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int arr[5];
    for (int i = 0; i < 5; i++)
    {
        cout << "Enter elements" << endl;
        cin >> arr[i];
    }
    printArray(arr, 5);

    return 0;
}