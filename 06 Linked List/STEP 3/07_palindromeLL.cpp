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

Node *midpoint(Node *head)
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

bool isPalindromic(Node *head)
{
    Node *left = head;
    Node *right = reverseLL(midpoint(head));

    while (left != NULL && right != NULL)
    {
        if (left->data != right->data)
        {
            return false;
        }
        left = left->next;
        right = right->next;
    }

    return true;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(12);
    Node *fourth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    if (isPalindromic(head))
    {
        cout<<"Yeah! It is Palindromic "<<endl;
    }
    else{
        cout<<"Nope! It is not Palindromic "<<endl;
    }
    

    return 0;
}