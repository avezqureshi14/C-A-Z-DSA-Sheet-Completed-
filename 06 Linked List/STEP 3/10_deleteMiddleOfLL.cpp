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

Node *middleNode(Node *&head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *deleteMiddleNode(Node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    
    Node *mid = middleNode(head);
    Node *temp = head;
    while (temp->next != mid)
    {
        temp = temp->next;
    }
    temp->next = mid->next;
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

    head->next = NULL;

    printLL(deleteMiddleNode(head));
    return 0;
}