#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *createTree(Node*root)
{
    int data;
    cout<<"Enter the data "<<endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout<<"Enter the data to the left of "<<data<<endl;
    root->left = createTree(root->left);
    cout<<"Enter the data to the right of "<<data<<endl;
    root->right = createTree(root->right);

    return root;
}




int main()
{
    Node*root = NULL;
    createTree(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
