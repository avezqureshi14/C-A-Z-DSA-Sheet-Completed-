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

int widthOfBT(Node *root)
{
    if (!root)
    {
        return 0;
    }
    int ans = 0;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int mmin = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int curr_id = q.front().second - mmin;
            Node *frontNode = q.front().first;
            q.pop();
            if (i == 0)
            {
                first = curr_id;
            }
            if (i == size - 1)
            {
                last = curr_id;
            }
            if (frontNode->left)
            {
                q.push({frontNode->left, curr_id*2+1});
            }
            if (frontNode->right)
            {
                q.push({frontNode->right, curr_id*2+2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

int main()
{
    Node *root = createBT();
    cout << widthOfBT(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1