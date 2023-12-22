#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class MyStack
{
private:
    int arr[1000];
    int top;

public:
    MyStack()
    {
        top = -1;
    };
    int pop();
    void push(int);
    void printStk();
};

void MyStack ::push(int x)
{
    top++;
    arr[top] = x;
}

int MyStack ::pop()
{
    if (top == -1)
    {
        return -1;
    }

    int x = arr[top];
    top--;
    return x;
}

void MyStack :: printStk(){
    for (int i = top; i >= 0; i--)
    {
        cout<<arr[i]<<" ";
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