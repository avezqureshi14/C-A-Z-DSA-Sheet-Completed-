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
//first = diameter
//second = height
pair<int,int>solveDiameterOFBT(Node*root){
    if (root == NULL)
    {
        pair<int,int>p = {0,0};
        return p;
    }
    pair<int,int>left = solveDiameterOFBT(root->left);
    pair<int,int>right = solveDiameterOFBT(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;
    pair<int,int>ans;
    ans.first = max(op1,max(op2,op3));
    ans.second = max(left.second,right.second) + 1;

    return ans;
}

int diameterOFBT(Node*root){
    if (root == NULL)
    {
        return 0;
    }
    return solveDiameterOFBT(root).first;
    
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    cout<<diameterOFBT(root);
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1