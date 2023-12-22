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

void zigZagTraversal(Node*root){
    if (root == NULL)
    {
        return;
    }
    queue<Node*>q;
    bool leftToright = true;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int>ans(size);
        for (int i = 0; i < size; i++)
        {
            Node*frontNode = q.front();
            q.pop();
            int index = leftToright ? i : size - i - 1;
            ans[index] = frontNode->data;
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        leftToright = !leftToright;
        for(auto i : ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}


int main()
{
    Node *root = NULL;
    root = createTree(root);
    zigZagTraversal(root);
    
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1