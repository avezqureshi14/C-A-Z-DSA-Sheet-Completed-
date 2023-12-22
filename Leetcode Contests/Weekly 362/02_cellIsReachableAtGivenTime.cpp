#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isReachableAtTime(int sx, int sy, int fx, int fy, int t)
{
    int diffX = abs(sx-fx);
    int diffY = abs(sy-fy);
    int minDistance = min(diffX,diffY);
    diffX = diffX - minDistance;
    diffY = diffY - minDistance;
    minDistance = minDistance + diffX + diffY;
    if (minDistance == 0)
    {
        //if start and end positions are same and if t is equal to 1 then it is not possible in that given time so we have to return false
        return t != 1;
    }

    //if our time is distance to travel is less than the time given then we will return true
    return minDistance <= t;
}
int main()
{
    int sx = 2;
    int sy = 2;
    int fx = 2;
    int fy = 2;
    int t = 1;
    cout<<isReachableAtTime(sx,sy,fx,fy,t);
    return 0;
}