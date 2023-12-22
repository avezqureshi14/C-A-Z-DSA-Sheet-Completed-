#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int data)
    {
        this->val = data;
        this->next = NULL;
    }
};

void insertIntoHeap(ListNode *node, priority_queue<int, vector<int>, greater<int>> &minHeap)
{
    while (node != NULL)
    {
        minHeap.push(node->val);
        node = node->next;
    }
}

void insertToTail(ListNode *&head, int newData)
{
    ListNode*newNode = new ListNode(newData);
    if (head == NULL)
    {
        head = newNode;
        return ;
    }
    ListNode*temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
}

void printLL(ListNode*node){
    while (node != NULL)
    {
        cout<<node->val<<" ";
        node = node->next;
    }
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    ListNode*result = NULL;
    int n = lists.size();
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        insertIntoHeap(lists[i], minHeap);
    }

    while (!minHeap.empty())
    {
        int top = minHeap.top();
        minHeap.pop();
        insertToTail(result,top);
    }
    

    return result;
}
int main()
{
    ListNode *headA = new ListNode(1);
    ListNode *secondA = new ListNode(4);
    ListNode *thirdA = new ListNode(5);
    headA->next = secondA;
    secondA->next = thirdA;
    thirdA->next = NULL;

    ListNode *headB = new ListNode(1);
    ListNode *secondB = new ListNode(3);
    ListNode *thirdB = new ListNode(4);
    headB->next = secondB;
    secondB->next = thirdB;
    thirdB->next = NULL;

    ListNode *headC = new ListNode(2);
    ListNode *secondC = new ListNode(6);
    headC->next = secondC;
    secondC->next = NULL;

    vector<ListNode *> lists;
    lists.push_back(headA);
    lists.push_back(headB);
    lists.push_back(headC);

    printLL(mergeKLists(lists));
    return 0;
}