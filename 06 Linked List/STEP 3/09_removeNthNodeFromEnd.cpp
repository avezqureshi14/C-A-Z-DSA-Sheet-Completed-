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

Node *removeNthNodeFromEnd(Node *&head, int n)
{
    Node *last = head;
    int len = 1;
    while (last->next != NULL)
    {
        last = last->next;
        len++;
    }
    cout<<len<<endl;

    Node *curr = head;
    int pos = 1;
    while (curr && curr->next)
    {
        curr = curr->next;
        pos++;
        if (pos == len - n)
        {
            curr->next = curr->next->next;
            return head;
        }
    }
    return head;
}

void printLL(Node*node){
    while (node)
    {
        cout<<node->data<<"-> ";
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

    printLL(removeNthNodeFromEnd(head,2));
    return 0;
}