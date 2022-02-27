/*
/*
** @Author: Sandeep Thapar
**
** Insert and delete nodes in a singly linked list
** 3 cases for insert - insert at beginning, insert at end, insert at a specific index
** 3 cases for delete - delete from beginning, delete from end, delete at a specific index
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** Linked List Playlist: https://youtube.com/playlist?list=PLFj4kIJmwGu1oI1HVzAZlpJgKf9xv6mM1
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
    if (prevNode->next == NULL)
        return;
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
    printList(head); // A

    insertAtEnd(head, 'B');
    printList(head); // A->B
    
    insertAtEnd(head, 'C');
    printList(head); // A->B->C
    
    insertAtBeginning(head, 'D');
    printList(head); // D->A->B->C
    
    insertAtBeginning(head, 'E');
    printList(head); // E->D->A->B->C
    
    insertAtIndex(head, 2, 'F');
    printList(head); // E->D->F->A->B->C
    
    deleteFromBeginning(head);
    printList(head); // D->F->A->B->C
    
    deleteAtIndex(head, 2);
    printList(head); // D->F->B->C
    
    deleteFromEnd(head);
    printList(head); // D->F->B
    
    deleteAtIndex(head, 1);
    printList(head); // D->B
    
    deleteAtIndex(head, 0);
    printList(head); // B
    
    deleteAtIndex(head, 5);
    printList(head); // B

    return 0;
}
