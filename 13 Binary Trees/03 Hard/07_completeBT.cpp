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

int findHeightLeft(Node *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->left;
    }
    return height;
}

int findHeightRight(Node *node)
{
    int height = 0;
    while (node)
    {
        height++;
        node = node->right;
    }
    return height;
}

int countNodes(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int lh = findHeightLeft(root);
    int rh = findHeightRight(root);

    if (lh == rh)
    {
        return pow(2, lh) - 1;
    }
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int main()
{
    Node *root = createBT();
    cout<<countNodes(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1