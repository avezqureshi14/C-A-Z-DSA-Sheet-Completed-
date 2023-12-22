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

Node *oddEvenList(Node *&head)
{
    Node *odd = head;
    Node *even = head->next;
    Node *evenHead = even;
    while (even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenHead;

    return head;
}

void printLL(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "-> ";
        node = node->next;
    }
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);
    Node *fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    printLL(oddEvenList(head));

    return 0;
}