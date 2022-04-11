#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        this->data = val;
        next = NULL;
    }
};
void printLinkedList(Node *head);
void insertAtBegin(Node *&head, int value);
void insertAtEnd(Node *head, int value);
int lengthOfLinkedList(Node *head);
void insertAtN(Node *head, int value, int position);
void deleteAtPosition(Node *&head, int position);
void deleteValue(Node *&head, int value);
void reverseNode(Node *&head);

int main(int argc, char const *argv[])
{
    Node *head = NULL;
    Node *tail = NULL;

    // insertAtBegin(head, 25);
    // insertAtBegin(head, 20);
    // insertAtBegin(head, 15);
    // insertAtBegin(head, 10);
    insertAtEnd(head, 30);
    insertAtEnd(head, 35);
    cout << "sdf" << sizeof(head);
    printLinkedList(head);
    cout << endl;
    cout << lengthOfLinkedList(head) << endl;
    insertAtN(head, 55, 4);
    printLinkedList(head);
    return 0;
}

void printLinkedList(Node *head)
{
    cout << "List is: ";
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void insertAtBegin(Node *&head, int value)
{
    Node *temp = new Node(value);
    temp->next = head;
    head = temp;
}

void insertAtEnd(Node *head, int value)
{
    Node *temp = new Node(value);
    while (head->next != NULL)
        head = head->next;
    head->next = temp;
}

int lengthOfLinkedList(Node *head)
{
    if (head == NULL)
        return 0;
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

void insertAtN(Node *head, int value, int position)
{
    if (position == 1)
    {
        Node *temp = new Node(value);
        temp->next = head;
        head = temp;
    }
    else
    {
        int n = 0;
        Node *tempHead = head;
        while (n != position || tempHead->next != NULL)
        {
            n++;
            tempHead = tempHead->next;
            cout << tempHead->data << " ";
        }
        Node *temp = new Node(value);
        temp->next = tempHead->next;
        tempHead->next = temp;
    }
}