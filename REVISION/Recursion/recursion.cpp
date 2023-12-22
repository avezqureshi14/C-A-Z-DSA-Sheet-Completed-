#include <iostream>
#include <bits/stdc++.h>
using namespace std;
double powe(int x, int num)
{
    long long n = num;
    if (num < 0)
    {
        (-1) * num;
    }
    double ans = 1.0;
    while (n)
    {
        if (n % 2)
        {
            ans = ans * x;
            n = n - 1;
        }
        else
        {
            x = x * x;
            n = n / 2;
        }
    }
    return ans;
}

void sortInserted(stack<int> &stk, int val)
{
    if (stk.empty() || stk.top() <= val)
    {
        stk.push(val);
        return;
    }
    int store = stk.top();
    stk.pop();
    sortInserted(stk, val);
    stk.push(store);
}

void sortAStack(stack<int> &stk)
{
    if (stk.empty())
    {
        return;
    }
    int val = stk.top();
    stk.pop();
    sortAStack(stk);
    sortInserted(stk, val);
}

void reverseStk(stack<int> &St)
{
    stack<int> temp;
    while (!St.empty())
    {
        int top = St.top();
        St.pop();
        temp.push(top);
    }
    St = temp;
}

void solve(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums)
{
    if (index == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[index]);
    solve(index + 1, ans, ds, nums);
    ds.pop_back();
    solve(index + 1, ans, ds, nums);
}
// just normal thing most simplest way to print powerset
vector<vector<int>> subsets(vector<int> &nums)
{
    int index = 0;
    vector<int> ds;
    vector<vector<int>> ans;
    solve(index, ans, ds, nums);
    return ans;
}

int solvePS(int index, vector<int> &nums, int sum, int k)
{
    if (index == nums.size() && sum == k)
    {
        return 1;
    }
    if (index == nums.size() && sum != k)
    {
        return 0;
    }
    return solvePS(index + 1, nums, sum + nums[index], k) +
           solvePS(index + 1, nums, sum, k);
}

int perfectSum(vector<int> &nums, int k)
{
    int index = 0;
    return solvePS(index, nums, 0, k);
}

bool solveCE(int index, vector<int> &nums, int sum, int k)
{
    if (index == nums.size() && sum == k)
    {
        return true;
    }
    if (index == nums.size() && sum != k)
    {
        return false;
    }

    return solveCE(index + 1, nums, sum + nums[index], k) ||
           solveCE(index + 1, nums, sum, k);
}
bool checkSumExist(vector<int> &nums, int k)
{
    if (solveCE(0, nums, 0, k))
    {
        return true;
    }
    else
    {
        return false;
    }
}

// slight change just after creating powerset as it is allowed a number can be repeated that's why we have didn't incremented index in first recursive call  , next thing to be noted is the backtracking process
void solveCombI(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int sum, int target)
{
    if (sum == target)
    {
        ans.push_back(ds);
        return;
    }

    if (index == nums.size() || sum > target)
    {
        return;
    }
    ds.push_back(nums[index]);
    solveCombI(index, ans, ds, nums, sum + nums[index], target);
    ds.pop_back();
    solveCombI(index + 1, ans, ds, nums, sum, target);
}

vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    int index = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    solveCombI(index, ans, ds, candidates, 0, target);
    return ans;
}

void solveCombII(int index, vector<vector<int>> &ans, vector<int> &ds, vector<int> &nums, int target)
{
    if (target == 0)
    {
        ans.push_back(ds);
        return;
    }

    if (target < 0)
    {
        return;
    }

    for (int i = index; i < nums.size(); i++)
    {
        if (i > index && nums[i] == nums[i - 1])
        {
            continue;
        }
        ds.push_back(nums[i]);
        solveCombII(i + 1, ans, ds, nums, target - nums[i]);
        ds.pop_back();
    }
}

vector<vector<int>> combinationSumII(vector<int> candidates, int target)
{
    int index = 0;
    vector<vector<int>> ans;
    vector<int> ds;
    solveCombII(index, ans, ds, candidates, target);
    return ans;
}

void solvePhone(int index, vector<string> &ans, string &output, string &digits, vector<string> &mapping)
{
    if (index >= digits.length())
    {
        ans.push_back(output);
        return;
    }
    int number = digits[index] - '0';
    string value = mapping[number];
    for (int i = 0; i < value.length(); i++)
    {
        output.push_back(value[i]);
        solvePhone(index + 1, ans, output, digits, mapping);
        output.pop_back();
    }
}

vector<string> letterCombinations(string digits)
{
    int index = 0;
    string output;
    vector<string> ans;
    vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (digits.length() == 0)
    {
        return ans;
    }
    solvePhone(index, ans, output, digits, mapping);
    return ans;
}

bool isPalindrom(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
        {
            return false;
        }
        start++;
        end--;
    }

    return true;
}

void solvePart(int index, vector<string> &ds, vector<vector<string>> &ans, string &s)
{
    if (index == s.length())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = index; i < s.length(); i++)
    {
        if (isPalindrom(s, index, i))
        {
            ds.push_back(s.substr(index, i - index + 1));
            solvePart(i + 1, ds, ans, s);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    int index = 0;
    vector<string> ds;
    vector<vector<string>> ans;
    solvePart(index, ds, ans, s);
    return ans;
}

vector<vector<string>>nQueen(int n){
    vector<vector<string>>ans;
    vector<string>board(n);
    string s(n,'.');
    //the above board have been initialized
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int>leftRow(n,0);
    vector<int>upperDiagonal(2*n-1,0);
    vector<int>lowerDiagonal(2*n-1,0);
    return ans;
}

int main()
{
    string s = "aab";
    for (auto i : partition(s))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}