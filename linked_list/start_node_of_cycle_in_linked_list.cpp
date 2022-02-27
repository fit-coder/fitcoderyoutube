/*
** @Author: Sandeep Thapar
**
** Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
** There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
** following the next pointer.
**
** e.g Input: A->B->C->D->E->F->G->H->I
**                     |..............|
** Cycle present as next node of I is D.
** Output: D
**
** e.g Input: A->B->C->D
** Output: NULL
**
** I have explained 2 methods to solve this problem
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

ListNode* startNodeCycle1(ListNode* head)
{
    unordered_set<ListNode*> us;
    while (head)
    {
        if (us.find(head) != us.end())
            return head;
        us.emplace(head);
        head = head->next;
    }
    return NULL;
}

ListNode* startNodeCycle2(ListNode* head)
{
    if (head == NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        {
            slow = head;
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}

int main()
{
    ListNode *head1 = NULL;
    insertAtBeginning(head1, 'I'); // I
    ListNode* nodeI = head1;
    insertAtBeginning(head1, 'H'); // H->I
    insertAtBeginning(head1, 'G'); // G->H->I
    insertAtBeginning(head1, 'F'); // F->G->H->I
    insertAtBeginning(head1, 'E'); // E->F->G->H->I
    insertAtBeginning(head1, 'D'); // D->E->F->G->H->I
    ListNode* nodeD = head1;
    insertAtBeginning(head1, 'C'); // C->D->E->F->G->H->I
    insertAtBeginning(head1, 'B'); // B->C->D->E->F->G->H->I
    insertAtBeginning(head1, 'A'); // A->B->C->D->E->F->G->H->I
    // Create cycle by connecting nodeI to nodeD   A->B->C->D->E->F->G->H->I
    //                                                      |..............|
    nodeI->next = nodeD; 

    ListNode *res1 = startNodeCycle1(head1); 
    if (res1 == NULL)
        cout << "No cycle in Linked List1 using method1" << endl;
    else
        cout << "Start node of cycle in Linked List1 using method1: " << res1->val << endl;
    res1 = startNodeCycle2(head1); 
    if (res1 == NULL)
        cout << "No cycle in Linked List1 using method2" << endl;
    else
        cout << "Start node of cycle in Linked List1 using method2: " << res1->val << endl;

    // Linked List example 2
    ListNode* head2 = NULL;
    insertAtBeginning(head2, 'D'); // D
    insertAtBeginning(head2, 'C'); // C->D
    insertAtBeginning(head2, 'B'); // B->C->D
    insertAtBeginning(head2, 'A'); // A->B->C->D
    ListNode *res2 = startNodeCycle1(head2); 
    if (res2 == NULL)
        cout << "No cycle in Linked List2 using method1" << endl;
    else
        cout << "Start node of cycle in Linked List2 using method1: " << res2->val << endl;
    res2 = startNodeCycle2(head2); 
    if (res2 == NULL)
        cout << "No cycle in Linked List2 using method2" << endl;
    else
        cout << "Start node of cycle in Linked List2 using method2: " << res2->val << endl;
    return 0;
}
