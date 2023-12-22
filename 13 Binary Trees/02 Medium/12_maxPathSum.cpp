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

int getMaxPathSum(Node *root, int &maxi)
{
    if (!root)
    {
        return 0;
    }
    int left = max(0, getMaxPathSum(root->left, maxi));
    int right = max(0, getMaxPathSum(root->right, maxi));

    //this is creating an umbrella
    //while making the umbrella we are even checking is it worth to create an umbrella what if root is negative so for that we are comparing it with so far maxi
    maxi = max(maxi, left + right + root->data);

    return max(left,right) + root->data;
}

int maxPathSum(Node *root)
{
    int maxi = INT_MIN;
    return maxi;
}

int main()
{
    Node *root = NULL;
    root = createTree(root);
    cout << maxPathSum(root);
    return 0;
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
// 1 2 3 4 -1 -1 4 -1 -1 3 -1 -1 2 -1 -1