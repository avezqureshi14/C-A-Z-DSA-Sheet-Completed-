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
        this->next = NULL;
        this->data = val;
    }
};

Node *reverseLL(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

Node *adding(Node *first, Node *second)
{
    int carry = 0;
    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (first != NULL || second != NULL || carry != 0)
    {
    }

    int val1 = 0;
    if (first != NULL)
    {
        val1 = first->data;
    }

    int val2 = 0;
    if (second != NULL)
    {
        val2 = second->data;
    }

    int sum = carry + val1 + val2;
}

Node *add1LL(Node *head1, Node *head2)
{
    Node *first = reverseLL(head1);
    Node *second = reverseLL(head2);

    Node *ans = adding(first, second);
}

int main()
{

    return 0;
}