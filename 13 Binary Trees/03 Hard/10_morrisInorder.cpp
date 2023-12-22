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

vector<int> morrisOrder(Node *root)
{
    vector<int> ans;
    if (!root)
    {
        return ans;
    }
    Node *curr = root;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }
        else
        {
            Node *pre = curr->left;
            while (pre->right != NULL && pre->right != curr)
            {
                pre = pre->right;
            }
            if (pre->right == NULL)
            {
                pre->right = curr;
                curr = curr->left;
            }
            else
            {
                pre->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    return ans;
}

int main()
{
    Node *root = createBT();
    for(auto i : morrisOrder(root)){
        cout<<i<<" ";
    }
    
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1