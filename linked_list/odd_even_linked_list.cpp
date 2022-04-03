/*
** @Author: Sandeep Thapar
**
** Given the head of a singly linked list, group all the nodes with odd indices
** together followed by the nodes with even indices, and return the reordered list.
** The first node is considered odd, and the second node is even, and so on.
**
** e.g Input: A->B->C->D->E
** Output: A->C->E->B->D
**
** e.g Input: A->Z->D->R->E->X
** Output: A->D->E->Z->R->X
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

ListNode* oddEvenList(ListNode* head) 
{
    if (head == NULL)
        return head;
    ListNode *odd = head;
    ListNode *even = head->next;
    ListNode *evenHead = even;
    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;
        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

pair<ListNode*, ListNode*> createLinkedLists()
{
    ListNode* head1 = NULL, *head2 = NULL;
    insertAtBeginning(head1, 'E'); // E
    insertAtBeginning(head1, 'D'); // D->E
    insertAtBeginning(head1, 'C'); // C->D->E
    insertAtBeginning(head1, 'B'); // B->C->D->E
    insertAtBeginning(head1, 'A'); // A->B->C->D->E

    insertAtBeginning(head2, 'X'); // X
    insertAtBeginning(head2, 'E'); // E->X
    insertAtBeginning(head2, 'R'); // R->E->X
    insertAtBeginning(head2, 'D'); // D->R->E->X
    insertAtBeginning(head2, 'Z'); // Z->D->R->E->X
    insertAtBeginning(head2, 'A'); // A->Z->D->R->E->X
    return {head1, head2};
}

int main()
{
    auto [head1, head2] = createLinkedLists();
    
    cout << "Linked List 1:";
    printList(head1); // A->B->C->D->E
    head1 = oddEvenList(head1);
    cout << "Linked List 1 after reordering:";
    printList(head1);
    cout << endl;

    cout << "Linked List 2:";
    printList(head2); // A->Z->D->R->E->X
    head2 = oddEvenList(head2);
    cout << "Linked List 2 after reordering:";
    printList(head2);

    return 0;
}
