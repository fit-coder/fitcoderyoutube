/*
** @Author: Sandeep Thapar
**
** Given two non-empty linked lists representing two non-negative integers.
** Each of their nodes contains a single digit.
** Add the two numbers and return the sum as a linked list.
**
** Note: Two numbers do not contain any leading zero, except the number 0 itself.
**
** e.g Input: list1 = 9->9->7->4->3
**            list2 = 8->7->5
** Output: 1->0->0->6->1->8
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

void insertAtBeginning(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

ListNode* reverse(ListNode *head)
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

int findLength(ListNode *head)
{
    int length = 0;
    while (head)
    {
        ++length;
        head = head->next;
    }
    return length;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int n1 = findLength(l1), n2 = findLength(l2), sum = 0;
    ListNode *head1 = l1, *head2 = l2, *head = NULL;
    while (n1 != 0 && n2 != 0)
    {
        if (n1 == n2)
        {
            sum = head1->val + head2->val;
            head1 = head1->next;
            head2 = head2->next;
            --n1;
            --n2;
        }
        else if (n1 < n2)
        {
            sum = head2->val;
            head2 = head2->next;
            --n2;
        }
        else if (n1 > n2)
        {
            sum = head1->val;
            head1 = head1->next;
            --n1;
        }
        insertAtBeginning(head, sum);
    }
    ListNode* curr = head, *prev = NULL;
    int carry = 0;
    while (curr != NULL)
    {
        int digit = (curr->val + carry) % 10;
        carry = (curr->val + carry) / 10;
        curr->val = digit;
        prev = curr;
        curr = curr->next;
    }
    if (carry != 0)
        prev->next = new ListNode(carry);
    head = reverse(head);
    return head;
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
    ListNode *head1 = NULL, *head2 = NULL;
    insertAtBeginning(head1, 3); // 3
    insertAtBeginning(head1, 4); // 4->3
    insertAtBeginning(head1, 7); // 7->4->3
    insertAtBeginning(head1, 9); // 9->7->4->3
    insertAtBeginning(head1, 9); // 9->9->7->4->3

    insertAtBeginning(head2, 5); // 5
    insertAtBeginning(head2, 7); // 7->5
    insertAtBeginning(head2, 8); // 8->7->5

    cout << "Number 1:";
    printList(head1);
    cout << "Number 2:";
    printList(head2);

    cout << "Number after addition:";
    ListNode *res = addTwoNumbers(head1, head2);
    printList(res);
    return 0;
}
