#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    Node*next;
    int data;
    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

void printLinkedList(Node*node){
    while (node != NULL)
    {
        cout<<node->data<<"-> ";
        node = node->next;
    }
}


int main()
{
    Node*first = new Node(1);
    Node*second = new Node(2);
    Node*third = new Node(3);
    Node*fourth = new Node(4);
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;    
    printLinkedList(first);

    return 0;
}