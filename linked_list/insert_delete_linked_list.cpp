/*
/*
** @Author: Sandeep Thapar
**
** Insert and delete nodes in a singly linked list
** 3 cases for insert - insert at beginning, insert at end, insert at a specific index
** 3 cases for delete - delete from beginning, delete from end, delete at a specific index
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    char val;
    ListNode *next;
    ListNode(char v)
    {
        val = v;
        next = NULL;
    }
};

void insertAtBeginning(ListNode *&head, char data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void insertAtIndex(ListNode *&head, int index, char data)
{
    if (index == 0 || head == NULL)
    {
        insertAtBeginning(head, data);
        return;
    }
    ListNode *newNode = new ListNode(data);
    ListNode *prevNode = head;
    for (int i=0; i < index-1; ++i)
    {
        if (prevNode == NULL)
            return;
        prevNode = prevNode->next;
    }
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void insertAtEnd(ListNode *&head, char data)
{
    ListNode *newNode = new ListNode(data);
    if (head == NULL)
    {
        insertAtBeginning(head, data);
        return;
    }
    ListNode *prevNode = head;
    while (prevNode->next != NULL)
        prevNode = prevNode->next;
    prevNode->next = newNode;
}

void deleteFromBeginning(ListNode *&head)
{
    if (head == NULL)
        return;
    ListNode* temp = head;
    head = head->next;
    delete temp;
}

void deleteAtIndex(ListNode *&head, int index)
{
    if (head == NULL || index < 0)
        return;
    if (index == 0)
    {
        deleteFromBeginning(head);
        return;
    }
    ListNode *prevNode = head;
    for (int i=0; i < index-1; ++i)
    {
        if (prevNode == NULL)
            return;
        prevNode = prevNode->next;
    }
    ListNode *temp = prevNode->next;
    prevNode->next = prevNode->next->next;
    delete temp;
}

void deleteFromEnd(ListNode *&head)
{
    if (head == NULL)
        return;
    if (head->next == NULL)
    {
        deleteFromBeginning(head);
        return;
    }
    ListNode *prevNode = head;
    while (prevNode != NULL && prevNode->next != NULL
           && prevNode->next->next != NULL)
    {
        prevNode = prevNode->next;
    }
    ListNode *temp = prevNode->next;
    prevNode->next = NULL;
    delete temp;
}

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = NULL;
    insertAtBeginning(head, 'A');
    printList(head);

    insertAtEnd(head, 'B');
    printList(head);
    
    insertAtEnd(head, 'C');
    printList(head);
    
    insertAtBeginning(head, 'D');
    printList(head);
    
    insertAtBeginning(head, 'E');
    printList(head);
    
    insertAtIndex(head, 2, 'F');
    printList(head);
    
    deleteFromBeginning(head);
    printList(head);
    
    deleteAtIndex(head, 2);
    printList(head);
    
    deleteFromEnd(head);
    printList(head);
    
    deleteAtIndex(head, 1);
    printList(head);
    
    deleteAtIndex(head, 0);
    printList(head);
    
    deleteAtIndex(head, 5);
    printList(head);

    return 0;
}
