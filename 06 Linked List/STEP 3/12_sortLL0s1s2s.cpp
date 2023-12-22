#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *next;
    int data;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node *sort0s1s2s(Node *head)
{
    Node *temp = head;
    int zeroCount = 0;
    int onesCount = 0;
    int twosCount = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
        {
            zeroCount++;
            temp = temp->next;
        }
        else if (temp->data == 1)
        {
            onesCount++;
            temp = temp->next;
        }
        else if (temp->data == 2)
        {
            twosCount++;
            temp = temp->next;
        }
    }

    temp = head;
    while (temp!= NULL)
    {
        if (zeroCount > 0)
        {
            temp->data = 0;
            temp = temp->next;
            zeroCount--;
        }
        else if(onesCount > 0){
            temp->data = 1;
            temp = temp->next;
            onesCount--;
        }
        else if(twosCount > 0){
            temp->data = 2;
            temp = temp->next;
            twosCount--;
        }
    }

    return head;
    
}



void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(2);
    Node *fourth = new Node(1);
    Node *fifth = new Node(2);
    Node *sixth = new Node(0);
    Node *seven = new Node(2);
    Node *eight = new Node(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;
    eight->next = NULL;

    printList(sort0s1s2s(head));

    return 0;
}