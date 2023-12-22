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

Node *createBT()
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    Node *root = new Node(data);
    cout << "Enter the data to the left of " << data << endl;
    root->left = createBT();
    cout << "Enter the data to the right of " << data << endl;
    root->right = createBT();
    return root;
}


Node *LCA(Node *&root, int root1, int root2)
{
    if (!root)
    {
        return NULL;
    }
    if (root->data == root1)
    {
        return root;
    }
    if (root->data == root2)
    {
        return root;
    }
    Node *leftTrv = LCA(root->left, root1, root2);
    Node *rightTrv = LCA(root->right, root1, root2);
    if (leftTrv == NULL)
    {
        return rightTrv;
    }
    else if (rightTrv == NULL)
    {
        return leftTrv;
    }
    else
    {
        return root;
    }

    return NULL;
}

int main()
{
    Node *root = createBT();
    cout << LCA(root, 7, 11)->data;
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1