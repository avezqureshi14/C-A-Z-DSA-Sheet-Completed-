#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int KthMissingElement(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= k)
        {
            k++;
        }else{
            break;
        }
    }
    return k;    
}
int main()
{
    int a[] = {1,3,5,7};
    int n = sizeof(a) / sizeof(a[0]);
    int k =2;
    cout << KthMissingElement(a, n, k);
    return 0;
}