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

// left =  (ps+1    , ps+nL , is   , iR-1);
// right = (ps+nL+1 , pe    , iR+1 , ie);

Node *getTree(vector<int> &preOrder, int preStart, int preEnd, vector<int> &inOrder, int inStart, int inEnd, map<int, int> inMap)
{
    if (preStart > preEnd || inStart > inEnd)
    {
        return NULL;
    }
    Node *root = new Node(preOrder[preStart]);

    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = getTree(preOrder, preStart + 1, preStart + numsLeft, inOrder, inStart, inRoot - 1, inMap);
    root->right = getTree(preOrder, preStart + numsLeft + 1, preEnd, inOrder, inRoot + 1, inEnd, inMap);
    return root;
}

Node *buildTree(vector<int> &preOrder, vector<int> &inOrder)
{
    map<int, int> inMap;
    for (int i = 0; i < inOrder.size(); i++)
    {
        inMap[inOrder[i]] = i;
    }

    Node *root = getTree(preOrder, 0, preOrder.size() - 1, inOrder, 0, inOrder.size() - 1, inMap);
    return root;
}

void levelOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<Node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << " ";
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
    }
}

int main()
{
    vector<int> inOrder = {9, 3, 15, 20, 7};
    vector<int> preOrder = {3, 9, 20, 15, 7};
    Node *root = buildTree(preOrder, inOrder);
    levelOrderTraversal(root);

    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1