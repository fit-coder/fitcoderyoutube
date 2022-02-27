/*
** @Author: Sandeep Thapar
**
** Given the head of a singly linked list, return the middle node of the linked list.
** If there are two middle nodes, return the second middle node.
**
** e.g Input: A->B->C->D->E
** Output: C->D->E
**
** e.g Input: A->B->C->D->E->F
** Output: D->E->F
**
** I have explained 3 methods to solve this problem
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

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

ListNode* findMiddle1(ListNode* head)
{
    if (head == NULL)
        return head;
    vector<ListNode*> v;
    while (head != NULL)
    {
        v.emplace_back(head);
        head = head->next;
    }
    return v[v.size()/2];
}

ListNode* findMiddle2(ListNode* head)
{
    if (head == NULL)
        return head;
    ListNode *mid = head;
    int count = 0;
    while (head != NULL)
    {
        ++count;
        head = head->next;
    }
    for (int i=0; i < count/2; ++i)
        mid = mid->next;
    return mid;
}

ListNode* findMiddle3(ListNode* head)
{
    if (head == NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

int main()
{
    ListNode *head = NULL;
    insertAtBeginning(head, 'F'); // F
    insertAtBeginning(head, 'E'); // E->F
    insertAtBeginning(head, 'D'); // D->E->F
    insertAtBeginning(head, 'C'); // C->D->E->F
    insertAtBeginning(head, 'B'); // B->C->D->E->F
    insertAtBeginning(head, 'A'); // A->B->C->D->E->F

    cout << "List :";
    printList(head); // A->B->C->D->E->F
    cout << "Middle of List using Method 1:";
    ListNode* mid = findMiddle1(head);
    printList(mid); // D->E->F

    cout << "Middle of List using Method 2:";
    mid = findMiddle2(head);
    printList(mid); // D->E->F

    cout << "Middle of List using Method 3:";
    mid = findMiddle3(head);
    printList(mid); // D->E->F

    return 0;
}
