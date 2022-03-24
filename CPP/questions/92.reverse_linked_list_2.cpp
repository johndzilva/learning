// 92. Reverse Linked List II
// Medium

// Given the head of a singly linked list and two integers left and right where left <= right,
// reverse the nodes of the list from position left to position right, and return the reversed list.

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

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

void insertAtEnd(ListNode *head, int value)
{
    ListNode *temp = new ListNode(value);
    while (head->next != NULL)
        head = head->next;
    head->next = temp;
}

void printLinkedList(ListNode *head)
{
    cout << "List is: ";
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (left == 1 && right == 1 || head->next == nullptr)
        return head;

    int currentPos = 1;
    ListNode *currentNode = head;
    ListNode *start = head;

    while (currentPos < left)
    {
        start = currentNode;
        currentNode = currentNode->next;
        currentPos++;
    }

    ListNode *prev = nullptr;
    ListNode *tail = currentNode;
    while (currentPos >= left && currentPos <= right)
    {
        ListNode *n = currentNode->next;
        currentNode->next = prev;
        prev = currentNode;
        currentNode = n;
        currentPos++;
    }
    start->next = prev;
    tail->next = currentNode;

    if (left > 1)
        return head;
    else if (left == 1)
        return prev;
    else
        return head;
}

int main(int argc, char const *argv[])
{
    ListNode *head = new ListNode(1);
    insertAtEnd(head, 2);
    insertAtEnd(head, 3);
    insertAtEnd(head, 4);
    insertAtEnd(head, 5);
    printLinkedList(head);

    head = reverseBetween(head, 2, 4);
    printLinkedList(head);
    return 0;
}
