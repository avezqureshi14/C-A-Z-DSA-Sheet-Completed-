#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class TreeNode
{
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        this->val = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode *buildTree(TreeNode *root)
{
    int data;
    cout << "Enter the data " << endl;
    cin >> data;
    if (data == -1)
    {
        return NULL;
    }
    root = new TreeNode(data);
    cout << "Enter data to the left of " << endl;
    root->left = buildTree(root->left);
    cout << "Enter data to the right of " << endl;
    root->right = buildTree(root->right);
    return root;
}

unordered_map<int, vector<int>> mp;

void dfs(TreeNode *curr, int currentLevel)
{
    if (curr == NULL)
    {
        return;
    }
    dfs(curr->left, currentLevel + 1);
    mp[currentLevel].push_back(curr->val);
    dfs(curr->right, currentLevel + 1);
}

int cycleSort(vector<int> &nums)
{
    int n = nums.size();
    unordered_map<int, int> indMap;
    for (int i = 0; i < n; i++)
    {
        indMap[nums[i]] = i;
    }
    sort(nums.begin(), nums.end());
    vector<bool> visited(n, false);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (visited[i] || indMap[nums[i]] == i)
        {
            continue;
        }

        int j = i, cycleSize = 0;
        while (!visited[j])
        {
            visited[j] = true;
            j = indMap[nums[j]];
            cycleSize++;
        }
        if (cycleSize > 0)
        {
            ans += (cycleSize - 1);
        }
    }
    return ans;
}

int minimumOperations(TreeNode *root)
{
    int ans = 0;
    if (root == NULL)
    {
        return ans;
    }
    dfs(root, 0);
    for (auto i : mp)
    {
        vector<int> &currList = i.second;
        ans += cycleSort(currList);
    }
    return ans;
}

int main()
{
    TreeNode *root = NULL;
    root = buildTree(root);

    cout << minimumOperations(root);

    return 0;
}

//  1 4 7 -1 -1 6 -1 -1 3 8 9 -1 -1 -1 5 10 -1 -1 -1 -1