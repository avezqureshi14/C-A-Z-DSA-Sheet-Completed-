#include <iostream>
#include <bits/stdc++.h>
using namespace std;


//funtion to print array
void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
}

int main()
{
    int arr[] = {1,2,3,4,56};
    int n = sizeof(arr)/sizeof(arr[0]);   
    printArray(arr,n); 
    return 0;
}