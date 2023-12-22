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

int findMinTime(Node *target, map<Node *, Node *> &parent)
{
    queue<Node *> q;
    q.push(target);
    int maxi = 0;
    map<Node *, bool> visited;
    while (!q.empty())
    {
        int flag = 0;
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            if (frontNode->left && !visited[frontNode->left])
            {
                flag = 1;
                visited[frontNode] = true;
                q.push(frontNode->left);
            }
            if (frontNode->right && !visited[frontNode->right])
            {
                flag = 1;
                visited[frontNode] = true;
                q.push(frontNode->right);
            }
            if (parent[frontNode] && !visited[parent[frontNode]])
            {
                flag = 1;
                visited[frontNode] = true;
                q.push(parent[frontNode]);
            }
        }
        if (flag)
        {
            maxi++;
        }
    }
    return maxi;
}

Node *mapParents(Node *root, map<Node *, Node *> &parent, int start)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode->data == start)
        {
            res = frontNode;
        }
        if (frontNode->left)
        {
            // parent of frontnode->left is frontNode
            parent[frontNode->left] = frontNode;
            q.push(frontNode->left);
        }
        if (frontNode->right)
        {
            parent[frontNode->right] = frontNode;
            q.push(frontNode->right);
        }
    }
    return res;
}

int timeToBurnTree(Node *root, int start)
{
    map<Node *, Node *> parent;
    Node *target = mapParents(root, parent, start);
    int maxi = findMinTime(target,parent);
    return maxi;
}

int main()
{
    Node *root = createBT();
    cout<<timeToBurnTree(root,11);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

//first map nodes to their parent and along with this find target node
//maintain a visited map and go on marking it visited, by visiting nodes parent, left and right and maintain a flag if anyone of all are burned then just increase the time by 1
//return the min time to burn the tree at the end