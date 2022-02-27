/*
** @Author: Sandeep Thapar
**
** Given the heads of 2 sorted linked lists head1 and head2, merge the 2 lists into 1 sorted linked list
** and return its head.
**
** e.g Input: head1 = 1->2->7->18
**            head2 = 1->8->9>10->30
** Output: 1->1->2->7->8->9->10->18->30
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
    int val;
    ListNode *next;
    ListNode(int v)
    {
        val = v;
        next = NULL;
    }
};

void insertAtBeginning(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

ListNode* mergeTwoLists(ListNode* head1, ListNode* head2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prevNode = dummy;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->val < head2->val)
        {
            prevNode->next = head1;
            head1 = head1->next;
        }
        else
        {
            prevNode->next = head2;
            head2 = head2->next;
        }
        prevNode = prevNode->next;
    }
    if (head1 != NULL)
        prevNode->next = head1;
    if (head2 != NULL)
        prevNode->next = head2;
    ListNode *res = dummy->next;
    delete dummy;
    return res;
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
    insertAtBeginning(head1, 18); // 18
    insertAtBeginning(head1, 7); // 7->18
    insertAtBeginning(head1, 2); // 2->7->18
    insertAtBeginning(head1, 1); // 1->2->7->18

    ListNode *head2 = NULL;
    insertAtBeginning(head2, 40); // 40
    insertAtBeginning(head2, 30); // 30->40
    insertAtBeginning(head2, 10); // 10->30->40
    insertAtBeginning(head2, 9); // 9->10->30->40
    insertAtBeginning(head2, 8); // 8->9->10->30->40
    insertAtBeginning(head2, 1); // 1->8->9->10->30->40

    cout << "Sorted Linked List1 :";
    printList(head1);
    cout << "Sorted Linked List2 :";
    printList(head2);

    cout << "Merged Sorted List :";
    ListNode *res = mergeTwoLists(head1, head2);
    printList(res);
    return 0;
}
