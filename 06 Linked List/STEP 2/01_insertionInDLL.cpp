#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtTail(Node *&head, int new_data)
{
    Node *new_node = new Node(new_data);
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;
    new_node->prev = last;
    new_node->next = NULL;
}

void insertAtHead(Node *&head, int new_data)
{
    Node *new_node = new Node(new_data);
    new_node->next = head;
    new_node->prev = NULL;

    head = new_node;
}

void insertAfter(Node *&head, int new_data, int pos)
{
    Node*new_node = new Node(new_data);
    int count = 1;
    Node*temp = head;
    while (count != pos)
    {
        count++;
        temp = temp->next;
    }
    temp->next->prev = new_node;
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    
}
void insertAt(Node *&head, int new_data, int pos)
{
    Node*new_node = new Node(new_data);
    int count = 1;
    Node*temp = head;
    while (count != pos-1)
    {
        count++;
        temp = temp->next;
    }
    temp->next->prev = new_node;
    new_node->next = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    
}

void printData(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << "-> ";
        node = node->next;
    }
    cout << "NULL ";
}

int main()
{

    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    // prevs
    head->prev = NULL;
    second->prev = head;
    third->prev = second;
    fourth->prev = third;

    // next
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    insertAtTail(head, 7);
    insertAtHead(head, 10);
    insertAfter(head,85,3);
    insertAt(head,83,3);
    printData(head);
    return 0;
}