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

int solve(Node* &root, int input,int &ans) {
    if (root == NULL) return ans;

    if (root->data == input)
    {
        return root->data;
    }
    if (root->data < input)
    {
        return solve(root->right,input,ans);
    }
    else{
        ans = root->data;
        return solve(root->left,input,ans);
    }
    return ans;
}
int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans = -1;
    return solve(root,input,ans);
}


int main()
{
    Node *root = NULL;
    root = buildTree(root);
    return 0;
}