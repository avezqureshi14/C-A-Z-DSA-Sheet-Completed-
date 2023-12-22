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

void deleteAtEnd(Node *&head)
{
    Node *last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = NULL;
}

void deleteAtStart(Node *&head)
{
    Node *temp = head->next;
    head = temp;
    head->prev = NULL;
}

void deleteAfter(Node *&head, int pos)
{
    Node *temp = head;
    int count = 1;
    while (count != pos && temp != nullptr)
    {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr || temp->next == nullptr)
    {
        cout << "Invalid position or no node to delete after." << endl;
        return;
    }

    Node *nodeToDelete = temp->next;
    temp->next = temp->next->next;
    if (temp->next != nullptr)
    {
        temp->next->prev = temp;
    }
    delete nodeToDelete;
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

    deleteAtEnd(head);
    deleteAtStart(head);
    deleteAfter(head,2);
    printData(head);
    return 0;
}