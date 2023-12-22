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

pair<int,bool>solveBalanced(Node*root){
    if (root == NULL)
    {
        pair<int,bool>p = {0,true};
        return p;
    }
    pair<int,bool>left = solveBalanced(root->left);
    pair<int,bool>right = solveBalanced(root->right);

    bool diff = abs(left.first - right.first) <= 1;
    pair<int,bool>ans;
    ans.first = max(left.first,right.first) + 1;
    ans.second = diff;
    
    return ans;
}

bool isBalanced(Node*root){
    if (root == NULL)
    {
        return true;
    }
    return solveBalanced(root).second;
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    if (isBalanced(root))
    {
        cout<<"yes";
    }
    else{
        cout<<"No";
    }
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1