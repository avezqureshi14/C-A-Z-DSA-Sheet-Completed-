#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void insertAtBottom(stack<int>&stk,int num){
    if (stk.empty())
    {
        stk.push(num);
        return;
    }
    int store =  stk.top();
    stk.pop();
    insertAtBottom(stk,num);
    stk.push(store);
}

void reverseAStack(stack<int>&stk){
    if (stk.empty())
    {
        return;
    }
    int store = stk.top();
    stk.pop();
    reverseAStack(stk);
    insertAtBottom(stk,store);
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
    stk.push(3);
    stk.push(2);
    stk.push(1);
    reverseAStack(stk);
    printStack(stk);

    return 0;
}