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

void deleteNode(Node *node){
    int temp = node->next->data;
    node->next->data = node->data;
    node->data = temp;
    node->next = node->next->next;
}

int main()
{   
    
    return 0;
}