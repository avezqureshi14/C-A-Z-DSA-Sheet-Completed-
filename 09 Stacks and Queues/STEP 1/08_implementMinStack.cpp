#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
    stack<int> stk1;
    stack<int> stk2;

public:
    void push(int x);
    int pop();
    void printStk();
    int getMin();
};

void MyStack ::push(int x)
{
    if (stk2.empty())
    {
        stk2.push(x);
    }
    if (x < stk2.top())
    {
        stk2.push(x);
    }

    stk1.push(x);
}

int MyStack ::getMin()
{
    return stk2.top();
}

int MyStack ::pop()
{
    int deleting = stk1.top();
    if (stk1.top() == stk2.top())
    {
        stk2.pop();
    }
    stk1.pop();
    return deleting;
}

void MyStack ::printStk(){
    stack<int>temp = stk1;
    while (!temp.empty())
    {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    
}


int main()
{
    MyStack stk;
    stk.push(2);
    stk.push(4);
    stk.push(1);
    stk.push(3);
    cout<<"The Popped element is "<<stk.pop()<<endl;
    cout<<"The minimum element is "<<stk.getMin()<<endl;
    stk.printStk();
    return 0;
}