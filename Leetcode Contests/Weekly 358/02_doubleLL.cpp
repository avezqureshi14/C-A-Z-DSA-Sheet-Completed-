#include <iostream>
#include <bits/stdc++.h>
using namespace std;
// Include necessary headers

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

ListNode *reverse(ListNode *head)
{
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr != NULL)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

void insertAtTail(ListNode *&ansHead, ListNode *&ansTail, ListNode *temp)
{
    if (ansHead == NULL)
    {
        ansHead = temp;
        ansTail = temp;
    }
    else
    {
        ansTail->next = temp;
        ansTail = temp;
    }
}

ListNode *add(ListNode *first, ListNode *second)
{
    ListNode *ansHead = NULL;
    ListNode *ansTail = NULL;
    int carry = 0;

    while (first || second || carry != 0)
    {
        int val1 = (first) ? first->val : 0;
        int val2 = (second) ? second->val : 0;

        int sum = val1 + val2 + carry;
        carry = sum / 10;
        int digit = sum % 10;

        ListNode *temp = new ListNode(digit);
        insertAtTail(ansHead, ansTail, temp);

        if (first)
            first = first->next;
        if (second)
            second = second->next;
    }

    return ansHead;
}

ListNode *doubleIt(ListNode *&head)
{
    ListNode *reversed = reverse(head);
    ListNode *ans = add(reversed, reversed);
    ans = reverse(ans);

    return ans;
}

void print(ListNode *&n)
{
    while (n != NULL)
    {
        cout << n->val << "-> ";
        n = n->next;
    }
}

int main()
{
    ListNode *head = new ListNode(9);
    ListNode *second = new ListNode(9);
    ListNode *third = new ListNode(9);
    head->next = second;
    second->next = third;

    ListNode *doubled = doubleIt(head);
    print(doubled);

    return 0;
}
