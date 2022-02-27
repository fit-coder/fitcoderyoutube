/*
** @Author: Sandeep Thapar
**
** Given two non-empty linked lists representing two non-negative integers.
** The digits are stored in reverse order, and each of their nodes contains a single digit.
** Add the two numbers and return the sum as a linked list.
**
** Note: Two numbers do not contain any leading zero, except the number 0 itself.
**
** e.g Input: list1 = 2->4->7
**            list2 = 3->9->4->9
** Output: 5->3->2->0->1
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

ListNode* addTwoNumbers(ListNode* head1, ListNode* head2)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *prevNode = dummy;
    int sum = 0, carry = 0;
    while (head1 != NULL || head2 != NULL)
    {
        int digit1 = 0, digit2 = 0;
        if (head1 != NULL)
        {
            digit1 = head1->val;
            head1 = head1->next;
        }
        if (head2 != NULL)
        {
            digit2 = head2->val;
            head2 = head2->next;
        }
        sum = digit1 + digit2 + carry;
        carry = sum / 10;
        prevNode->next = new ListNode(sum % 10);
        prevNode = prevNode->next;
    }
    if (carry != 0)
        prevNode->next = new ListNode(carry);
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
    ListNode *head1 = NULL, *head2 = NULL;
    insertAtBeginning(head1, 7); // 7
    insertAtBeginning(head1, 4); // 4->7
    insertAtBeginning(head1, 2); // 2->4->7

    insertAtBeginning(head2, 9); // 9
    insertAtBeginning(head2, 4); // 4->9
    insertAtBeginning(head2, 9); // 9->4->9
    insertAtBeginning(head2, 3); // 3->9->4->9

    cout << "Number 1:";
    printList(head1);
    cout << "Number 2:";
    printList(head2);

    cout << "Number after addition:";
    ListNode *res = addTwoNumbers(head1, head2);
    printList(res);
    return 0;
}
