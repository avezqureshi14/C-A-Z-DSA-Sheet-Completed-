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

Node *getIntersectionNode(Node *headA, Node *headB)
{
    if (headA == NULL || headB == NULL)
    {
        return NULL;
    }

    Node *a = headA;
    Node *b = headB;
    while (a != b)
    {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }
    return a;
}

int main()
{


    return 0;
}