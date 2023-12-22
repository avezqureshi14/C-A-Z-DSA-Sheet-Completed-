#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node *top = NULL;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }

    friend class MyStack;
};

class MyStack
{
private:
    Node *top;

public:
    MyStack()
    {
        top = NULL;
    }

    void push(int new_data);
    int pop();
    void printLL();
};

void MyStack::push(int x)
{
    Node *new_node = new Node(x);
    if (top == NULL)
    {
        top = new_node;
    }
    else
    {
        new_node->next = top;
        top = new_node;
    }
}

int MyStack::pop()
{
    if (top == NULL)
    {
        cout << "Stack is Empty. " << endl;
        return -1;
    }

    int popped = top->data;
    Node *temp = top;
    top = top->next;
    delete temp;
    return popped;
}

void MyStack ::printLL()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    MyStack stk;
    stk.push(1);
    stk.push(2);
    stk.push(3);
    stk.push(4);
    stk.printLL();

    cout << "Popped Elements " << stk.pop() << endl;
    stk.printLL();
    return 0;
}