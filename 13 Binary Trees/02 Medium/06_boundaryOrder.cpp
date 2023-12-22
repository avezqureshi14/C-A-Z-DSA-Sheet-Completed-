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

void traverseLeft(Node*root, vector<int>&ans){
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left,ans);
    }
    else{
        traverseLeft(root->right,ans);
    }
}

void traverseRight(Node*root, vector<int>&ans){
    if (root == NULL || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        traverseRight(root->right,ans);
    }
    else{
        traverseRight(root->left,ans);
    }
    ans.push_back(root->data);
}

void leafNodes(Node*root, vector<int>&ans){
    if (root==NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
    }
    leafNodes(root->left,ans);
    leafNodes(root->right,ans);
}

void boundaryOrder(Node*root){
    if (root == NULL)
    {
        return;
    }
    vector<int>ans;
    ans.push_back(root->data);
    traverseLeft(root->left,ans);
    leafNodes(root->left,ans);
    leafNodes(root->right,ans);
    traverseRight(root->right,ans);

    for(auto i : ans){
        cout<<i<<" ";
    }
}


int main()
{
    Node *root = NULL;
    root = createTree(root);
    boundaryOrder(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1