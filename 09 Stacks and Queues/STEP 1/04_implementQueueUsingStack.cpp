#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    stack<int> stk1;
    stack<int> stk2;

public:
    void push(int x);
    int pop();
    void printQ();
    bool isEmpty();
};

void MyQueue ::push(int x)
{
    stk1.push(x);
}
int MyQueue ::pop()
{
    while (!stk1.empty())
    {
        stk2.push(stk1.top());
        stk1.pop();
    }
    int deleting = stk2.top();
    stk2.pop();
    return deleting;
}
bool MyQueue ::isEmpty()
{
    if (stk1.empty() && stk2.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyQueue ::printQ(){
    stack<int>temp = stk2;
    while (!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    stack<int>temp2 = stk1;
    while (!temp2.empty())
    {
        cout<<temp2.top()<<" ";
        temp2.pop();
    }
}


int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    cout<<"The popped element is "<<q.pop()<<endl;
    q.printQ();
    return 0;
}