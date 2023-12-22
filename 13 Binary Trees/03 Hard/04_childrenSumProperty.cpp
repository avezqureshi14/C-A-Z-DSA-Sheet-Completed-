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

Node *createBT()
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    cout << "Enter the data to the left of " << data << endl;
    root->left = createBT();
    cout << "Enter the data to the right of " << data << endl;
    root->right = createBT();
    return root;
}

int sum(Node *root)
{
    if (root == NULL)
        return 0;

    return sum(root->left) + root->data +
           sum(root->right);
}

bool isSumTree(struct Node *node)
{
    int ls, rs;

    if (node == NULL ||
        (node->left == NULL &&
         node->right == NULL))
    {
        return true;
    }
    if (node->left)
    {
        ls = node->left->data;
    }
    else
    {
        ls = 0;
    }
    if (node->right)
    {
        rs = node->right->data;
    }
    else
    {
        rs = 0;
    }
    cout << "This is node = " << node->data << " This is ls = " << ls << " This is rs = " << rs << endl;
    if ((node->data == ls + rs) &&
        isSumTree(node->left) &&
        isSumTree(node->right))
    {
        return true;
    }

    return false;
}

void changeTree(Node *&root)
{
    if (root == NULL)
    {
        return;
    }
    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }
    if (root->right)
    {
        child += root->right->data;
    }
    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        else if (root->right)
        {
            root->right->data = root->data;
        }
    }
    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }
    if (root->left || root->right)
    {
        root->data = tot;
    }
}

void preOrder(Node *node)
{
    if (!node)
    {
        return;
    }
    cout << node->data << " ";
    preOrder(node->left);
    preOrder(node->right);
}

int main()
{
    Node *root = createBT();
    // changeTree(root);
    // preOrder(root);
    if (isSumTree(root) == 1)
    {
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }

    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 35 18 7 -1 -1 11 -1 -1 17 17 -1 -1 -1