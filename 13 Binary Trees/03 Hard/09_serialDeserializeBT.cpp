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

string serialize(Node*root){
    if (!root)
    {
        return "";
    }
    
    string ans = "";
    queue<Node*>q;
    q.push(root);
    while (!q.empty())
    {
        Node*currNode = q.front();
        q.pop();
        if (currNode == NULL)
        {
            ans.append("#, ");
        }else{
            ans.append(to_string(currNode->data) + ',');
        }
        if (currNode != NULL)
        {
            q.push(currNode->left);
            q.push(currNode->right);
        }
    }
    return ans;    
}



int main()
{
    Node *root = createBT();
    cout<<serialize(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1