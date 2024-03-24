#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    ListNode *next;
    int val;
    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

void linkedListData(ListNode *node, vector<int> &ans)
{

    while (node)
    {
        ans.push_back(node->val);
        node = node->next;
    }
}

vector<vector<int>> spiralMatrix(int m, int n, ListNode *head)
{
    vector<int> nodes;
    linkedListData(head, nodes);
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    int top = 0;
    int left = 0;
    int bottom = m - 1;
    int right = n - 1;
    int it = 0;
    while (it < nodes.size() && top <= bottom && left <= right)
    {
        // for moving left to right
        for (int i = left; i <= right; i++)
        {
            if (it < nodes.size())
            {
                matrix[top][i] = nodes[it];
                it++;
            }
        }
        top++;
        // for moving top to bottom
        for (int i = top; i <= bottom; i++)
        {
            if (it < nodes.size())
            {
                matrix[i][right] = nodes[it];
                it++;
            }
        }
        right--;
        if (top <= bottom)
        {
            // for moving right to left
            for (int i = right; i >= left; i--)
            {
                if (it < nodes.size())
                {
                    matrix[bottom][i] = nodes[it];
                    it++;
                }
            }
            bottom--;
        }
        // for moving bottom to top
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                if (it < nodes.size())
                {
                    matrix[i][left] = nodes[it];
                    it++;
                }
            }
            left++;
        }
    }

    return matrix;
}

int main()
{
    ListNode *head = new ListNode(3);
    ListNode *h2 = new ListNode(0);
    ListNode *h3 = new ListNode(2);
    ListNode *h4 = new ListNode(6);
    ListNode *h5 = new ListNode(8);
    ListNode *h6 = new ListNode(1);
    ListNode *h7 = new ListNode(7);
    ListNode *h8 = new ListNode(9);
    ListNode *h9 = new ListNode(4);
    ListNode *h10 = new ListNode(2);
    ListNode *h11 = new ListNode(5);
    ListNode *h12 = new ListNode(5);
    ListNode *h13 = new ListNode(0);
    head->next = h2;
    h2->next = h3;
    h3->next = h4;
    h4->next = h5;
    h5->next = h6;
    h6->next = h7;
    h7->next = h8;
    h8->next = h9;
    h9->next = h10;
    h10->next = h11;
    h11->next = h12;
    h12->next = h13;
    h13->next = NULL;
    for (auto i : spiralMatrix(3, 5, head))
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}