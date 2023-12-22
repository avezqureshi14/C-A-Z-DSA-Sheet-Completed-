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

Node *insertIntoBST(Node *root, int val)
{

    if (!root)
    {
        root = new Node(val);
        return root;
    }
    if (root->data > val)
    {
        root->left = insertIntoBST(root->left, val);
    }
    else
    {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

Node *buildTree(Node *root)
{

    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cout << "Enter the data " << endl;
        cin >> data;
    }
    return root;
}

void findPreSuc(Node *&root, Node *&pre, Node *&suc, int key)
{
    // Your code goes here
    if (root == NULL)
        return;
    Node *n;
    if (root->data < key)
    {
        pre = root;
        findPreSuc(root->right, pre, suc, key);
    }
    else if (root->data > key)
    {
        suc = root;
        findPreSuc(root->left, pre, suc, key);
    }
    else
    {
        findPreSuc(root->right, pre, suc, key);
        findPreSuc(root->left, pre, suc, key);
    }
}
int main()
{
    Node *root = NULL;
    root = buildTree(root);
    return 0;
}