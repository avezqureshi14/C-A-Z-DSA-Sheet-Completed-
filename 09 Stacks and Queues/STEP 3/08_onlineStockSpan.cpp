#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class StockSpan
{
    stack<pair<int, int>> stk;

public:
    int next(int price)
    {
        int span = 1;
        while (!stk.empty() && stk.top().first <= price)
        {
            span += stk.top().second;
            stk.pop();
        }
        stk.push({price, span});
        return stk.top().second;
    }
};
int main()
{
    StockSpan obj;
    cout<<obj.next(100)<<" ";
    cout<<obj.next(80)<<" ";
    cout<<obj.next(60)<<" ";
    cout<<obj.next(70)<<" ";
    cout<<obj.next(60)<<" ";
    cout<<obj.next(75)<<" ";
    cout<<obj.next(85)<<" ";
    return 0;
}