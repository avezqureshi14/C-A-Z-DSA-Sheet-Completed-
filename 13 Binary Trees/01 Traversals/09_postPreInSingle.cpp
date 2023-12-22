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

void preInPost(Node*root){
    stack<pair<Node*,int>>stk;
    stk.push({root,1});
    vector<int>in;
    vector<int>pre;
    vector<int>post;
    while (!stk.empty())
    {
        pair<Node*,int>top = stk.top();
        stk.pop();
        if (top.second == 1)
        {
            pre.push_back(top.first->data);
            top.second++;
            stk.push({top.first,top.second});
            if (top.first->left)
            {
                stk.push({top.first->left,1});
            }
        }
        else if (top.second == 2)
        {
            in.push_back(top.first->data);
            top.second++;
            stk.push({top.first,top.second});
            if (top.first->right)
            {
                stk.push({top.first->right,1});
            }
        }
        else{
            post.push_back(top.first->data);
        }
    }
    cout<<"PreOrder Traversal"<<endl;
    for(auto i : pre){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Inorder Traversal"<<endl;
    for(auto i : in){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"Post Traversal"<<endl;
    for(auto i : post){
        cout<<i<<" ";
    }
    cout<<endl;
    
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    preInPost(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
