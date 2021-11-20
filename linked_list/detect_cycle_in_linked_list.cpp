/*
** @Author: Sandeep Thapar
**
** Given head, the head of a linked list, determine if the linked list has a cycle in it.
** There is a cycle in a linked list if there is some node in the list that can be reached again by continuously
** following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is
** connected to. Note that pos is not passed as a parameter.
** Return true if there is a cycle in the linked list. Otherwise, return false.Given the head of a singly linked list,
** return the middle node of the linked list.
**
** e.g Input: A->B->C->D->E->F->G->H->I
**                     |..............|
** Cycle present as next node of I is D.
** Output: True
**
** e.g Input: A->B->C->D
** Output: False
**
** I have explained 2 methods to solve this problem
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

bool hasCycle1(ListNode* head)
{
    unordered_set<ListNode*> us;
    while (head)
    {
        if (us.find(head) != us.end())
            return true;
        us.emplace(head);
        head = head->next;
    }
    return false;
}

bool hasCycle2(ListNode* head)
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
            return true;
    }
    return false;
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

    string res;
    res = hasCycle1(head1) == 1 ? "True" : "False"; 
    cout << "Is cycle present in Linked List1 using first method: " << res << endl;
    res = hasCycle2(head1) == 1 ? "True" : "False"; 
    cout << "Is cycle present in Linked List1 using second method: " << res << endl;

    ListNode* head2 = NULL;
    insertAtBeginning(head2, 'D'); // D
    insertAtBeginning(head2, 'C'); // C->D
    insertAtBeginning(head2, 'B'); // B->C->D
    insertAtBeginning(head2, 'A'); // A->B->C->D
    res = hasCycle1(head2) == 1 ? "True" : "False"; 
    cout << "Is cycle present in Linked List2 using first method: " << res << endl;
    res = hasCycle2(head2) == 1 ? "True" : "False"; 
    cout << "Is cycle present in Linked List2 using second method: " << res << endl;
    return 0;
}
