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

vector<int> findNodes(map<Node *, Node *> &parent, Node *target, int k)
{
    queue<Node *> q;
    q.push(target);
    map<Node *, bool> visited;
    visited[target] = true;
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (level == k)
        {
            break;
        }
        level++;
        for (int i = 0; i < size; i++)
        {
            Node *frontNode = q.front();
            q.pop();
            if (frontNode->left && !visited[frontNode->left])
            {
                q.push(frontNode->left);
                visited[frontNode->left] = true;
            }
            if (frontNode->right && !visited[frontNode->right])
            {
                q.push(frontNode->right);
                visited[frontNode->right] = true;
            }
            if (parent[frontNode] && !visited[parent[frontNode]])
            {
                q.push(parent[frontNode]);
                visited[parent[frontNode]] = true;
            }
        }
    }
    vector<int> result;
    while (!q.empty())
    {
        result.push_back(q.front()->data);
        q.pop();
    }
    return result;
}

Node *mapParents(Node *root, map<Node *, Node *> &parent, int target)
{
    queue<Node *> q;
    q.push(root);
    Node *res;
    while (!q.empty())
    {
        Node *frontNode = q.front();
        q.pop();
        if (frontNode->data == target)
        {
            res = frontNode;
        }
        if (frontNode->left)
        {
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

vector<int> distanceK(Node *root, int target, int k)
{
    map<Node *, Node *> parent;
    Node *targetNode = mapParents(root, parent, target);
    vector<int> ans = findNodes(parent, targetNode, k);
    return ans;
}

int main()
{
    Node *root = createBT();
    int target = 5;
    int k = 2;
    for (auto i : distanceK(root, target, k))
    {
        cout << i << " ";
    }
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

// 3 5 6 -1 -1 2 7 -1 -1 4 -1 -1 1 0 -1 -1 8 -1 -1

//first map nodes to their parent and along with this find target node
//maintain a visited map and go on marking it visited, by visiting nodes parent, left and right and keep them pushing in our queue and along with this keep track of level if it is equal to k then stop and break from the while loop
//the remaining elements in our q is our answer 