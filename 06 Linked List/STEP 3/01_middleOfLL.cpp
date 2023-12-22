#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
};

Node *middleOfLinkedList(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast->next != NULL && fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void printLL(Node *node)
{
    while (node != NULL)
    {
        node = node->next;
        cout << node->data;
    }
}

int main()
{
    Node*head = new Node(1);
    Node*second = new Node(2);
    Node*third = new Node(3);
    Node*fourth = new Node(4);
    Node*fifth = new Node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    cout<<"Middle part of the LL is "<<middleOfLinkedList(head)->data;
    
    return 0;
}