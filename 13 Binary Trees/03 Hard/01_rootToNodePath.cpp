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

bool getPath(Node *root, vector<int> &ans, int x)
{
    //agar root nahi hai toh direct return false
    if (!root)
    {
        return false;
    }
    ans.push_back(root->data);
    if (root->data == x)
    {
        return true;
    }
    bool left = getPath(root->left, ans, x);
    bool right = getPath(root->right, ans, x);
    if (left || right)
    {
        return true;
    }
    ans.pop_back();
    return false;
}

vector<int> rootToNode(Node *node, Node *root)
{
    vector<int> ans;
    getPath(root, ans, node->data);
    return ans;
}

int main()
{
    Node *root = createBT();
    
    for (auto i : rootToNode(root->right->left, root))
    {
        cout << i << " ";
    }
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1