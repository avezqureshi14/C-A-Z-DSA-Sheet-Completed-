#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class SmallestInfiniteSet
{
    set<int> minSet;

public:
    SmallestInfiniteSet()
    {
        for (int i = 1; i < 1000; i++)
        {
            minSet.insert(i);
        }
    }

    int popSmallest()
    {
        int smallest = *minSet.begin();
        minSet.erase(minSet.begin());
        return smallest;
    }

    void addBack(int num)
    {
        minSet.insert(num);
    }
};

int main()
{
    SmallestInfiniteSet s;
    cout << s.popSmallest();
    return 0;
}