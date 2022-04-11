// 1721. Swapping Nodes in a Linked List

// You are given the head of a linked list, and an integer k.

// Return the head of the linked list after swapping the values of the kth node from the beginning and
// the kth node from the end (the list is 1-indexed).

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [1,4,3,2,5]

// Example 2:

// Input: head = [7,9,6,6,7,8,3,0,9,5], k = 5
// Output: [7,9,6,6,8,7,3,0,9,5]

#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *left = head;
    ListNode *right = head;
    ListNode *iter = head;
    int counter = 1;
    while (iter != NULL)
    {
        if (counter < k)
        {
            left = left->next;
        }
        else if (counter > k)
        {
            right = right->next;
        }
        iter = iter->next;
        counter++;
    }

    int temp = left->val;
    left->val = right->val;
    right->val = temp;
    return head;
}

void insertAtBegin(ListNode *&head, int value)
{
    ListNode *temp = new ListNode(value);
    temp->next = head;
    head = temp;
}

void print(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

int main(int argc, char const *argv[])
{
    ListNode *head = NULL;
    insertAtBegin(head, 5);
    insertAtBegin(head, 4);
    insertAtBegin(head, 3);
    insertAtBegin(head, 2);
    insertAtBegin(head, 1);
    head = swapNodes(head, 2);
    print(head);
    return 0;
}
