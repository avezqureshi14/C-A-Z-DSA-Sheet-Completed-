#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
    int data;
    Node *next;

public:
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    friend class MyQueue;
};

class MyQueue
{
    Node *front = NULL;
    Node *rear = NULL;

public:
    void push(int x);
    int pop();
    void printQ();
    bool isEmpty();
    bool isFull();
};

void MyQueue ::push(int x)
{
    Node *new_node = new Node(x);
    new_node->next = NULL;
    if (isEmpty())
    {
        front=new_node;
        rear= new_node;
    }
    rear->next = new_node;
    rear = new_node;
}

int MyQueue ::pop(){
    Node*temp = front;
    front=front->next;
    int deleting = temp->data;
    if (rear == NULL)
    {
        front = NULL;
    }
    return deleting;
}

bool MyQueue ::isEmpty()
{
    if (front == NULL && rear == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void MyQueue ::printQ(){
    Node*temp = front;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    MyQueue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.pop();
    q.printQ();
    return 0;
}