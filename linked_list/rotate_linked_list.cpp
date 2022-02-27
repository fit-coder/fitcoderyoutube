/*
** @Author: Sandeep Thapar
**
** Given the head of a singly linked list, rotate the linked list to right by k places
**
** e.g Input: A->B->C->D->E->F->G, K = 1
** Output: G->A->B->C->D->E->F
**
** e.g Input: A->B->C->D->E->F->G, K = 4
** Output: D->E->F->G->A->B->C
**
** e.g Input: A->B->C->D->E->F->G, K = 7
** Output: A->B->C->D->E->F->G
**
** e.g Input: A->B->C->D->E->F->G, K = 12
** Output: C->D->E->F->G->A->B
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

pair<ListNode*, int> findLastNode(ListNode* node)
{
    int length = 1;
    while (node->next != NULL)
    {
        ++length;
        node = node->next;
    }
    return {node, length};
}

ListNode* rotateLinkedList(ListNode* head, int k)
{
    if (head == NULL || k == 0)
        return head;

    auto [node, length] = findLastNode(head);

    // loop the list
    node->next = head;

    // handle the case of k>length
    k = k % length;

    // find the node to break the loop at
    for (int i=0; i < length-k; i++)
        node = node->next;

    head = node->next;
    node->next = NULL;
    return head;
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
    ListNode *head = createLinkedList();
    cout << "Linked List:";
    printList(head); // A->B->C->D->E->F->G

    ListNode *newHead = rotateLinkedList(head, 1);
    cout << "Rotate Linked List to right by 1 places:";
    printList(newHead);

    head = createLinkedList();
    newHead = rotateLinkedList(head, 4);
    cout << "Rotate Linked List to right by 4 places:";
    printList(newHead);

    head = createLinkedList();
    newHead = rotateLinkedList(head, 7);
    cout << "Rotate Linked List to right by 7 places:";
    printList(newHead);

    head = createLinkedList();
    newHead = rotateLinkedList(head, 12);
    cout << "Rotate Linked List to right by 12 places:";
    printList(newHead);

    return 0;
}
