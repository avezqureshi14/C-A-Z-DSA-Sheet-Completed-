#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// long long minimumPossibleSum(int n, int target) {
//     set<int> st;
//     long long ans = 0;
//     for(int i = 1; st.size() < n; ++i ){
//         if(st.find(target - i) == st.end()) { st.insert(i); ans += i; }
//     }
//     return ans;
// }

long long minimumPossibleSum(int n, int target)
{
    int x = target / 2;
    long long ans = 0;
    for (int i = 1; i <= x; i++)
    {
        ans += i;
        n--;
        if (n == 0)
        {
            break;
        }
    }
    int z = target;
    while (n--)
    {
        ans += z;
        z++;
    }
    return ans;
}
int main()
{
    int n = 16;
    int target = 6;
    cout << minimumPossibleSum(n, target);
    return 0;
}