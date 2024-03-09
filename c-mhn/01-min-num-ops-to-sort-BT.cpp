#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    TreeNode *left;
    TreeNode *right;
    int val;
    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *createTree(TreeNode *root)
{
    int val;
    cout << "Enter the value of TreeNode" << endl;
    cin >> val;
    if (val == -1)
    {
        return NULL;
    }
    root = new TreeNode(val);
    cout << "Enter the val to the left of " << val << endl;
    root->left = createTree(root->left);
    cout << "Enter the val to the right of " << val << endl;
    root->right = createTree(root->right);
    return root;
}

int countOps(vector<int> &inputArr)
{
    int count = 0;
    int n = inputArr.size();
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({inputArr[i], i});
    }
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++)
    {
        if (v[i].second == i)
            continue;
        else
        {
            count++;
            swap(v[i], v[v[i].second]);
            i--;
        }
    }
    return count;
}

int minimumOperations(TreeNode *root)
{
    int ans = 0;
    queue<TreeNode *> q;
    vector<int> inputArr;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        TreeNode *frontTreeNode = q.front();
        q.pop();
        if (frontTreeNode == NULL)
        {
            if (!q.empty())
            {
                q.push(NULL);
            }
            ans += countOps(inputArr);
            inputArr.clear();
        }
        else
        {
            inputArr.push_back(frontTreeNode->val);
            if (frontTreeNode->left)
            {
                q.push(frontTreeNode->left);
            }
            if (frontTreeNode->right)
            {
                q.push(frontTreeNode->right);
            }
        }
    }

    return ans;
}

int main()
{
    TreeNode *root = NULL;
    root = createTree(root);
    cout << minimumOperations(root);
    return 0;
}

// 1 4 7 -1 -1 6 -1 -1 3 8 9 -1 -1 -1 5 10 -1 -1 -1