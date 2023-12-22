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

int lengthOfLL(Node*node){
    int count = 0;
    while (node != NULL)
    {
        count++;
        node = node->next;
    }

    return count;
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

    cout<<"The Length of the LL "<<lengthOfLL(first);   
    return 0;
}