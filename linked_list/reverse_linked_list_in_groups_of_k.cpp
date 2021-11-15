/*
** @Author: Sandeep Thapar
**
** Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
** k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
** You may not alter the values in the list's nodes, only nodes themselves may be changed.
**
** e.g  Input: A->B->C->D->E->F->G->H, K = 3
** Output: C->B->A->F->E->D->G->H
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

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

// reverse “count” nodes starting from head.
// A->B->C->D->E->F->G. If C,3 is passed, function will reverse C->D->E and return {E,F}
pair<ListNode*,ListNode*> reverse(ListNode* head, int count)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *temp = curr->next;
    while (count > 0)
    {
        --count;
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return {prev, temp};
}

int findLength(ListNode *head)
{
    int len = 0;
    while (head)
    {
        ++len;
        head = head->next;
    }
    return len;
}

ListNode *reverseKGroup(ListNode *head, int k)
{
    if (head == NULL || k == 1)
        return head;
    int len = findLength(head);
    ListNode *beforeLeftNode = NULL;
    ListNode *leftNode = head;
    for (int i=0; i < len / k; ++i) 
    {
        auto [rightNode, afterRightNode] = reverse(leftNode, k);
        if (i == 0)
            head = rightNode;
        else
            beforeLeftNode->next = rightNode;
        leftNode->next = afterRightNode;

        beforeLeftNode = leftNode;
        leftNode = afterRightNode;
    }
    return head;
}

int main()
{
    ListNode *head = NULL;
    insertAtBeginning(head, 'H'); // H
    insertAtBeginning(head, 'G'); // G->H
    insertAtBeginning(head, 'F'); // F->G->H
    insertAtBeginning(head, 'E'); // E->F->G->H
    insertAtBeginning(head, 'D'); // D->E->F->G->H
    insertAtBeginning(head, 'C'); // C->D->E->F->G->H
    insertAtBeginning(head, 'B'); // B->C->D->E->F->G->H
    insertAtBeginning(head, 'A'); // A->B->C->D->E->F->G->H

    cout << "List :";
    printList(head); // A->B->C->D->E->F->G->H
    cout << "Reverse List in groups of 3:";
    head = reverseKGroup(head, 3);
    printList(head); // C->B->A->F->E->D->G->H

    return 0;
}
