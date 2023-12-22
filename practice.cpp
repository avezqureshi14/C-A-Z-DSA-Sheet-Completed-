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

void verticalOrder(Node*root){
    queue<pair<Node*,pair<int,int>>>q;
    q.push({root,{0,0}});
    map<int,map<int,vector<int>>>nodes;
    while (!q.empty())
    {
        Node*frontNode = q.front().first;
        int hd = q.front().second.first;
        int lvl = q.front().second.second;
        q.pop();
        nodes[hd][lvl].push_back(frontNode->data);
        if (frontNode->left)
        {
            q.push({frontNode->left,{hd-1,lvl+1}});
        }
        if (frontNode->right)
        {
            q.push({frontNode->right,{hd+1,lvl+1}});
        }
    }
    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                cout<<k<<" ";
            }
        }
    }
}


int main()
{
    Node *root = NULL;
    root = createTree(root);
    verticalOrder(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
