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

bool isIsomorphic(Node *root1, Node *root2)
{
    if (root1 == NULL && root2 == NULL)
    {
        return true;
    }
    if (root1 == NULL && root2 != NULL || root1 != NULL && root2 == NULL)
    {
        return false;
    }
    if (root1->data == root2->data || root1->left->data == root2->right->data || root1->right->data == root2->left->data)
    {
        return true;
    }
    bool left = isIsomorphic(root1->left, root2->left);
    bool right = isIsomorphic(root1->right, root2->right);

    return left && right;
}
int main()
{
    Node *root1 = NULL;
    Node *root2 = NULL;
    createTree(root1);
    createTree(root2);
    cout<<isIsomorphic(root1,root2);

    // 1 2 4 -1 -1 5 7 -1 -1 8 -1 -1 3 6 -1 -1 -1
    // 1 3 -1 6 -1 -1 2 4 -1 -1 5 8 -1 -1 7 -1 -1
    return 0;
}