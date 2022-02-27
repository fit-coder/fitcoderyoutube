/*
** @Author: Sandeep Thapar
**
** Given the heads of two singly linked-lists head1 and head2, return the node at which the two lists intersect. 
** If the two linked lists have no intersection at all, return null.
**
** e.g Input: head1 = A->B->C->D->W->X->Y->Z
**    head2 = M->N->O->P->Q->R->S-|
** Output: W
**
** e.g Input: head1 = A->B->C->D, head2 = E->F->G
** Output: NULL
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
 
 int getLength(ListNode *head)
 {
    int len = 0;
    while (head->next != NULL)
    {
        ++len;
        head = head->next;
    }
    return len;
 }
 ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
 {
    if (head1 == NULL || head2 == NULL)
        return NULL;
    ListNode *res = NULL;
    int n1 = getLength(head1);
    int n2 = getLength(head2);
    int diff = abs (n1-n2);
    if (n1 > n2)
    {
        while (diff > 0)
        {
            --diff;
            head1 = head1->next;
        }
    }
    else if (n1 < n2)
    {
        while (diff > 0)
        {
            --diff;
            head2 = head2->next;
        }
    }
    while (head1 != NULL && head2 != NULL && head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1;
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
    ListNode *head1 = NULL;
    insertAtBeginning(head1, 'Z'); // Z
    insertAtBeginning(head1, 'Y'); // Y->Z
    insertAtBeginning(head1, 'X'); // X->Y->Z
    insertAtBeginning(head1, 'W'); // W->X->Y->Z
    ListNode *nodeW = head1;
    insertAtBeginning(head1, 'D'); // D->W->X->Y->Z
    insertAtBeginning(head1, 'C'); // C->D->W->X->Y->Z
    insertAtBeginning(head1, 'B'); // B->C->D->W->X->Y->Z
    insertAtBeginning(head1, 'A'); // A->B->C->D->W->X->Y->Z

    ListNode *head2 = NULL;
    insertAtBeginning(head2, 'S'); // S
    head2->next = nodeW;  // S->W->X->Y->Z
    insertAtBeginning(head2, 'R'); // R->S->W->X->Y->Z
    insertAtBeginning(head2, 'Q'); // Q->R->S->W->X->Y->Z
    insertAtBeginning(head2, 'P'); // P->Q->R->S->W->X->Y->Z
    insertAtBeginning(head2, 'O'); // O->P->Q->R->S->W->X->Y->Z
    insertAtBeginning(head2, 'N'); // N->O->P->Q->R->S->W->X->Y->Z
    insertAtBeginning(head2, 'M'); // M->N->O->P->Q->R->S->W->X->Y->Z

    cout << "Linked List1 :";
    printList(head1);
    cout << "Linked List2 :";
    printList(head2);

    ListNode *res = getIntersectionNode(head1, head2);
    if (res == NULL)
        cout << "Linked Lists don't intersect" << endl;
    else
        cout << "Intersection node: " << res->val << endl;
    return 0;
}
