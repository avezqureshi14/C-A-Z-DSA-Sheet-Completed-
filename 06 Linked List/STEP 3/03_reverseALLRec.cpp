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

Node *reverseLLRecursive(Node *&head, Node *prev = nullptr)
{
    if (head == nullptr || head->next == nullptr)
    {
        head->next = prev;
        return head;
    }

    Node *temp = head->next;
    head->next = prev;
    prev = head;
    head = temp;

    return reverseLLRecursive(head, prev);
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

    reverseLLRecursive(head);
    printLL(head);
    return 0;
}