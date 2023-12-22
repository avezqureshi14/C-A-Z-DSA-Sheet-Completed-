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

void traversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}

Node *minValue(Node *root)
{
    if (!root)
    {
        return NULL;
    }
    while (root->left)
    {
        root = root->left;
    }
    return root;
}

Node *deleteNode(Node *&root, int key)
{
    if (!root)
    {
        return nullptr;
    }

    if (root->data == key)
    {
        if (!root->left)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        if (!root->right)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *minRight = minValue(root->right);
        root->data = minRight->data;
        root->right = deleteNode(root->right, minRight->data);
    }
    else if (root->data > key)
    {
        root->left = deleteNode(root->left, key);
    }
    else
    {
        root->right = deleteNode(root->right, key);
    }
    return root;
}

int main()
{
    Node *root = NULL;
    root = buildTree(root);
    traversal(root);
    return 0;
}