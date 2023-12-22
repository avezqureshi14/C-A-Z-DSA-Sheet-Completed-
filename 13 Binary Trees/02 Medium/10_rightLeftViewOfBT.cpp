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

Node *createTree(Node *root)
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new Node(data);
    cout << "Enter the data to the left of " << data << endl;
    root->left = createTree(root->left);
    cout << "Enter the data to the right of " << data << endl;
    root->right = createTree(root->right);

    return root;
}

void leftView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";

    if (root->left)
    {
        leftView(root->left);
    }
    else
    {
        leftView(root->right);
    }
}

void rightView(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    if (root->right)
    {
        rightView(root->right);
    }
    else
    {
        rightView(root->left);
    }
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    leftView(root);
    cout<<endl;
    rightView(root);
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1