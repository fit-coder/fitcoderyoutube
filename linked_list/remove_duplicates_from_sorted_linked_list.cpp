/*
** @Author: Sandeep Thapar
**
** Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct
** numbers from the original list. Return the linked list sorted as well.
**
** e.g Input: 1->2->2->2->2->3->3->4->5
** Output: 1->4->5
**
** e.g Input: 1->1->1->2
** Output: 2
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
    int val;
    ListNode *next;
    ListNode(int v)
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

ListNode* removeDuplicates(ListNode* head)
{
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    ListNode* prev = dummy;
    ListNode* curr = head;
    while (curr)
    {
        while (curr->next && curr->val == curr->next->val)
            curr = curr->next;
        if (prev->next == curr)
            prev = prev->next;
        else
            prev->next = curr->next;
        curr = curr->next;
    }
    ListNode* res = dummy->next;
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
    ListNode *head = NULL;
    insertAtBeginning(head, 5); // 5
    insertAtBeginning(head, 4); // 4->5
    insertAtBeginning(head, 3); // 3->4->5
    insertAtBeginning(head, 3); // 3->3->4->5
    insertAtBeginning(head, 2); // 2->3->3->4->5
    insertAtBeginning(head, 2); // 2->2->3->3->4->5
    insertAtBeginning(head, 2); // 2->2->2->3->3->4->5
    insertAtBeginning(head, 2); // 2->2->2->2->3->3->4->5
    insertAtBeginning(head, 1); // 1->2->2->2->2->3->3->4->5

    cout << "Linked List before removing duplicates :";
    printList(head);
    head = removeDuplicates(head);
    cout << "Linked List after removing duplicates :";
    printList(head);
    return 0;
}
