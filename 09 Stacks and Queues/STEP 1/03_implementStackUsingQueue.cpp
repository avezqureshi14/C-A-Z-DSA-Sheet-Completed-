#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int x);
    int pop();
    bool isEmpty();
    void printStk();
};

void MyStack ::push(int x)
{
    q1.push(x);
}

int MyStack ::pop()
{
    while (q1.size() > 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int deleting = q1.front();
    q1.pop();
    swap(q1, q2);
    return deleting;
}

bool MyStack ::isEmpty()
{
    if (q1.empty() && q2.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyStack ::printStk()
{
    queue<int>temp = q1;
    while (!temp.empty())
    {
        cout<<temp.front()<<" ";
        temp.pop();
    }
}

int main()
{
    MyStack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.pop();
    stk.printStk();
    return 0;
}