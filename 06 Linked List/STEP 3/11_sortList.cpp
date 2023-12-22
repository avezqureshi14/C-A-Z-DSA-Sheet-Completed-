#include <iostream>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;

    ListNode(int val) : data(val), next(NULL) {}
};

ListNode *merge(ListNode *l1, ListNode *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;

    ListNode *result = NULL;

    if (l1->data <= l2->data)
    {
        result = l1;
        result->next = merge(l1->next, l2);  
    }
    else
    {
        result = l2;
        result->next = merge(l1, l2->next);
    }

    return result;
}

ListNode *getMiddle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;

    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (prev)
        prev->next = NULL;

    return slow;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *middle = getMiddle(head);
    ListNode *left = sortList(head);
    ListNode *right = sortList(middle);

    return merge(left, right);
}



void printList(ListNode *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = new ListNode(1);
    ListNode *second = new ListNode(2);
    ListNode *third = new ListNode(2);
    ListNode *fourth = new ListNode(1);
    ListNode *fifth = new ListNode(2);
    ListNode *sixth = new ListNode(0);
    ListNode *seven = new ListNode(2);
    ListNode *eight = new ListNode(2);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seven;
    seven->next = eight;
    eight->next = NULL;

    printList(sortList(head));

    return 0;
}
