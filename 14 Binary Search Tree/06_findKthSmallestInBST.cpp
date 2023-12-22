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

void inorderBST(Node *&root, vector<int> &inorder)
{
    if (!root)
    {
        return;
    }
    inorderBST(root->left, inorder);
    inorder.push_back(root->data);
    inorderBST(root->right, inorder);
}
int kthSmallest(Node *&root, int k)
{
    if (!root)
    {
        return -1;
    }
    vector<int> inorder;
    inorderBST(root, inorder);
    return inorder[k - 1];
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    return 0;
}