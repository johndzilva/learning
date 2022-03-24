// 148. Sort List
// Medium

// Given the head of a linked list, return the list after sorting it in ascending order.

// Example 1:

// Input: head = [4,2,1,3]
// Output: [1,2,3,4]

#include <iostream>

using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode(int val)
    {
        this->val = val;
        next = NULL;
    }
};

ListNode *mergeTwoLists(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    ListNode *newHead = NULL;
    if (a->val < b->val)
    {
        newHead = a;
        newHead->next = mergeTwoLists(a->next, b);
    }
    else
    {
        newHead = b;
        newHead->next = mergeTwoLists(a, b->next);
    }
    return newHead;
}

ListNode *sortList(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    ListNode *n = slow->next;
    slow->next = NULL;

    ListNode *a = sortList(head);
    ListNode *b = sortList(n);

    head = mergeTwoLists(a, b);
    return head;
}

int main(int argc, char const *argv[])
{
    // call the function with i/p
    return 0;
}
