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

// Function to insert a node at the beginning of the linked list.
Node *insertAtBegining(Node *&head, int x)
{
    if (head == NULL)
    {
        head = new Node(x);
        return head;
    }
    Node *new_node = new Node(x);
    new_node->next = head;
    head = new_node;
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

// Function to insert a node at the end of the linked list.
Node *insertAtEnd(Node *&head, int x)
{
    Node*new_node = new Node(x);
    if (head == NULL)
    {
        head = new_node;
        return head;
    }

    Node*last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    
    last->next = new_node;
    new_node->next = NULL;

    return head;
}

int main()
{
    Node *head = NULL;
    insertAtEnd(head, 4);
    insertAtEnd(head, 3);
    insertAtEnd(head, 2);
    insertAtEnd(head, 1);
    printLL(head);
    return 0;
}