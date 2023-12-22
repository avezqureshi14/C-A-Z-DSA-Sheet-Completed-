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

bool isIdentical(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }

    if (root1 != NULL && root2 == NULL || root1 == NULL && root2 != NULL)
    {
        return false;
    }

    bool checkData = root1->data == root2->data;
    bool left = isIdentical(root1->left, root2->left);
    bool right = isIdentical(root1->right, root2->right);

    return checkData && left && right;
}

bool isSymmetric(Node *root)
{
    if (!root)
    {
        return true;
    }

    return isIdentical(root->left, root->right);
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    if (isSymmetric(root))
    {
        cout << "yes";
    }
    else
    {
        cout << "No";
    }
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1