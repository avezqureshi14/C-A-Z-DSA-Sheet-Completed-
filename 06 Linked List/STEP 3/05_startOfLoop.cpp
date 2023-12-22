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

Node *startingPointOfLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast!= NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return 0;
}

int main()
{
    Node *head = new Node(3);
    Node *second = new Node(2);
    Node *third = new Node(0);
    Node *fourth = new Node(4);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = second;
    cout << "The starting point of Loop is " << startingPointOfLoop(head)->data;
    return 0;
}