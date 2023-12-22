#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void update(int a[], int n, int updates[], int k)
{
    int i = 0;
    int j = 0;

    while (i <= n)
    {
        if (i == 0)
        {
            int m = j;
            while (m <= n)
            {
                a[m] = a[m] + 1;
                m++;
            }
        }
        else
        {
            if (updates[i] == updates[i - 1])
            {
                int m = j;
                while (m <= n)
                {
                    a[m] = a[m] + 1;
                    m++;
                }
            }
            else if (updates[i] != updates[i - 1])
            {
                j++;
                int m = j;
                while (m <= n)
                {
                    a[m] = a[m] + 1;
                    m++;
                }
            }
        }
        i++;
    }
}
int main()
{
    int a[] = {0,0,0};
    int n = 2;
    int updates[] = {1,1,1};
    int k = 3;
    update(a,n,updates,k);
    for (int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }
    
    return 0;
}