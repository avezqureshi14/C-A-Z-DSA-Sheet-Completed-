#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *insertIntoBST(TreeNode *root, int val)
{

    if (!root)
    {
        root = new TreeNode(val);
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

TreeNode *buildTree(TreeNode *root)
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

TreeNode *searchBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == val)
    {

        return root;
    }
    if (root->data < val)
    {
        return searchBST(root->right, val);
    }
    else
    {
        return searchBST(root->left, val);
    }
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree(root);

    return 0;
}