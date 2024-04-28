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

bool search(Node *root, int x)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->data == x)
    {
        return true;
    }
    bool leftSearch = false, rightSearch = false;
    if (root->data < x)
    {
        rightSearch = search(root->right, x);
    }
    else
    {
        leftSearch = search(root->left, x);
    }

    return leftSearch || rightSearch;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    if (search(root, 4))
    {
        cout << "Yeah";
    }
    else
    {
        cout << "Nope";
    }

    return 0;
}