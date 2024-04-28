#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *insertToBST(TreeNode *root, int val)
{
    if (root == NULL)
    {
        root = new TreeNode(val);
        return root;
    }
    if (root->val > val)
    {
        root->left = insertToBST(root->left, val);
    }
    else if (root->val < val)
    {
        root->right = insertToBST(root->right, val);
    }
    return root;
}

TreeNode *buildTree(TreeNode *root)
{
    int val;
    cout << "Enter the val " << endl;
    cin >> val;
    while (val != -1)
    {
        root = insertToBST(root, val);
        cout << "Enter the val " << endl;
        cin >> val;
    }
    return root;
}

void inOrder(vector<int> &inorder, TreeNode *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(inorder, root->left);
    inorder.push_back(root->val);
    inOrder(inorder, root->right);
}

vector<int> binarySearch(int x, int low, int high, vector<int> v)
{
    int mini = -1, maxi = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (v[mid] == x)
            return {v[mid], v[mid]};

        if (v[mid] < x)
        {
            low = mid + 1;
            mini = v[mid];
        }
        else
        {
            high = mid - 1;
            maxi = v[mid];
        }
    }
    return {mini, maxi};
}
vector<vector<int>> closestNodes(TreeNode *root, vector<int> &queries)
{
    vector<int> inorder;
    vector<vector<int>> ans;
    inOrder(inorder, root);
    for (auto i : queries)
    {

        ans.push_back(binarySearch(i, 0, queries.size(), inorder));
    }
    return ans;
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree(root);
    // traversal(root);
    vector<int> queries = {2, 5, 16};
    for (auto i : closestNodes(root, queries))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}

// 6 2 13 1 4 9 15 14 -1