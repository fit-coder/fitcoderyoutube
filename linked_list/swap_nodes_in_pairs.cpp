/*
** @Author: Sandeep Thapar
**
** Given a linked list, swap every two adjacent nodes and return its head.
** You must solve the problem without modifying the values in the list's nodes (i.e., only nodes
** themselves may be changed.)
**
** e.g Input: A->B->C->D->E->F
** Output: B->A->D->C->F->E
**
** e.g Input: A->B->C->D->E->F->G
** Output: B->A->D->C->F->E->G
**
** I have explained both the recursive and iterative method to solve this
**
** For video explanation, please refer to my Youtube channel (Fit Coder) in the link below:
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
    ListNode()
    {
        val = ' ';
        next = NULL;
    }
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

ListNode* swapPairs_recursive(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *temp = head->next;
    head->next = swapPairs_recursive(temp->next);
    temp->next = head;
    return temp;
}

ListNode* swapPairs_iterative(ListNode* head)
{
    ListNode* dummy = new ListNode();
    ListNode* prev = dummy;
    ListNode* curr = head;
    dummy->next = head;
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        curr->next = curr->next->next;
        prev->next->next = curr;
        prev = curr;
        curr = curr->next;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
}

ListNode* createLinkedList()
{
    ListNode *head = NULL;
    insertAtBeginning(head, 'G'); // G
    insertAtBeginning(head, 'F'); // F->G
    insertAtBeginning(head, 'E'); // E->F->G
    insertAtBeginning(head, 'D'); // D->E->F->G
    insertAtBeginning(head, 'C'); // C->D->E->F->G
    insertAtBeginning(head, 'B'); // B->C->D->E->F->G
    insertAtBeginning(head, 'A'); // A->B->C->D->E->F->G
    return head;
}

int main()
{
    ListNode* head = createLinkedList();
    cout << "Linked List:";
    printList(head); // A->B->C->D->E->F->G
    ListNode *newHead = swapPairs_recursive(head);
    cout << "Linked List after swapping adjacent pairs using recursive method:";
    printList(newHead);

    head = createLinkedList(); // A->B->C->D->E->F->G
    newHead = swapPairs_iterative(head);
    cout << "Linked List after swapping adjacent pairs using iterative method:";
    printList(newHead);

    return 0;
}
