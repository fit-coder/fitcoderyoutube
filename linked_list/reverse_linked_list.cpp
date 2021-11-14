/*
** @Author: Sandeep Thapar
**
** Reverse a singly linked list
** It can be done both iteratively and recursively.
**
** e.g Input: A->B->C->D->E
** Output: E->D->C->B->A
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

ListNode* reverseListIterative(ListNode* head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

ListNode* reverseListRecursive(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *temp = reverseListRecursive(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

int main()
{
    ListNode *head1 = NULL;
    insertAtBeginning(head1, 'E'); // E
    insertAtBeginning(head1, 'D'); // D->E
    insertAtBeginning(head1, 'C'); // C->D->E
    insertAtBeginning(head1, 'B'); // B->C->D->E
    insertAtBeginning(head1, 'A'); // A->B->C->D->E

    cout << "List :";
    printList(head1); // A->B->C->D->E
    cout << "Reverse List using Iterative Method:";
    head1 = reverseListIterative(head1);
    printList(head1); // E->D->C->B->A
    cout << endl;

    ListNode *head2 = NULL;
    insertAtBeginning(head2, 'E'); // E
    insertAtBeginning(head2, 'D'); // D->E
    insertAtBeginning(head2, 'C'); // C->D->E
    insertAtBeginning(head2, 'B'); // B->C->D->E
    insertAtBeginning(head2, 'A'); // A->B->C->D->E

    cout << "List :";
    printList(head2); // A->B->C->D->E
    cout << "Reverse List using Recursive Method:";
    head2 = reverseListRecursive(head2);
    printList(head2); // E->D->C->B->A

    return 0;
}
