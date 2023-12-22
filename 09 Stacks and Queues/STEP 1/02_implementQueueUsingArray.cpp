#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class MyQueue
{
    int arr[1000];
    int front;
    int rear;
    int currentSize = 0;

public:
    MyQueue();
    void enqueue(int x);
    int dequeue();
    bool isFull();
    bool isEmpty();
    void printQ();
};

MyQueue ::MyQueue()
{
    int front = 0;
    int rear = -1;
}

void MyQueue ::enqueue(int x){
    if (isFull())
    {
        cout<<"Q is completely filled";
    }

    rear = (rear + 1) % 1000;
    arr[rear] = x;
    currentSize++;
}

int MyQueue ::dequeue(){
    if (isEmpty())
    {
        cout<<"Q is current Empty"<<endl;
    }
    int deleting = arr[front];
    front = (front + 1) % 1000;
    currentSize--;
    return deleting;
}



bool MyQueue ::isFull()
{
    if (currentSize == 1000)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool MyQueue ::isEmpty()
{
    if (currentSize == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}





void MyQueue::printQ() {
    for (int i = front; i <= rear; i++)
    {
        cout<<arr[i]<<" ";
    }
}


int main()
{
    MyQueue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.printQ();
    return 0;
}