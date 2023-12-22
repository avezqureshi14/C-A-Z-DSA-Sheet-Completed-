#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// int slowStart(int X, int H)
// {
//     int ans = 0;
//     int count = 0;
//     int half = X / 2;
//     for (int i = 0; i < 5; i++)
//     {
//         ans = ans + half;
//         count++;
//         if (ans > H)
//         {
//             return count;
//         }
//     }
//     int remain;
//     if (H > ans)
//     {
//         remain = H - ans;
//     }
//     ans = ceil(remain / X);
//     return ans;
// }

int slowStart(int X, int H)
{
    int sum = 0;
    int count = 0;
    int half = X / 2;
    for (int i = 0; i < 5; i++)
    {
        sum = sum + half;
        count++;
        if (sum > H)
        {
            return count;
        }
    }

    while (sum < H)
    {
        sum = sum + X;
        count++;
    }
    return count;
}

int main()
{
    int T;
    cin>>T;
    for (int i = 0; i < T; i++)
    {
        int X;
        cin >> X;
        int H;
        cin >> H;
        cout << slowStart(X, H);
    }
    return 0;
}