#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertedSorted(stack<int> &stk, int new_num)
{
    if (stk.empty() || stk.top() < new_num)
    {
        stk.push(new_num);
        return;
    }
    
    int store = stk.top();
    stk.pop();
    insertedSorted(stk,new_num);
    stk.push(store);
}

void sortAStack(stack<int>&stk){
    if (stk.empty())
    {
        return;
    }
    int top = stk.top();
    stk.pop();
    sortAStack(stk);
    insertedSorted(stk,top);
}

void printStack(stack<int> stk)
{
    while (!stk.empty())
    {
        cout << stk.top()<<" ";
        stk.pop();
    }
}

int main()
{
    stack<int> stk;
    stk.push(4);
    stk.push(2);
    stk.push(7);
    sortAStack(stk);
    printStack(stk);

    return 0;
}