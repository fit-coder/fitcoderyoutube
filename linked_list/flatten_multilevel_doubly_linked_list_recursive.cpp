/*
** @Author: Sandeep Thapar
**
** You are given a doubly linked list, which contains nodes that have a next pointer,
** a previous pointer, and an additional child pointer. This child pointer may or may not
** point to a separate doubly linked list, also containing these special nodes.
** Given the head of the first level of the list, flatten the list so that all the nodes
** appear in a single-level, doubly linked list
**
** Here I have explained recursive method to solve this problem.
**
** Input:
** A <=> B <=> C <=> D <=> E <=> F
**             |
**             G <=> H <=>I <=> J
**             |                |
**             K                L <=> M <=> N
**                              |
**                              O
**
** Output: A <=> B <=> C <=> G <=> K <=> H <=> I <=> J <=> L <=> O <=> M <=> N <=> D <=> E <=> F
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
    ListNode *prev;
    ListNode *child;
    ListNode(char v)
    {
        val = v;
        next = NULL;
        prev = NULL;
        child = NULL;
    }
};

ListNode* insertAtBeginning(ListNode *&head, char data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    if (head != NULL)
        head->prev = newNode;
    head = newNode;
    return newNode;
}

ListNode *flatten(ListNode *node)
{
    if (node == NULL)
        return node;
    ListNode* childNode = node->child;
    ListNode* nextNode = node->next;
    ListNode* childLast = flatten(childNode);
    ListNode* nextLast = flatten(nextNode);
    node->child = NULL;
    if (childLast != NULL)
    {
        node->next = childNode;
        childNode->prev = node;
        node = childLast;
    }
    if (nextLast != NULL)
    {
        node->next = nextNode;
        nextNode->prev = node;
        node = nextLast;
    }
    return node;
}

ListNode* flatten_recursive(ListNode *head)
{
    ListNode *res = head;
    flatten(head);
    return res;
}

void printList(ListNode *head)
{
    ListNode* h = head;
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
}

/*
** Creates the following multi level doubly linked list
**
** A <=> B <=> C <=> D <=> E <=> F
**             |
**             G <=> H <=>I <=> J
**             |                |
**             K                L <=> M <=> N
**                              |
**                              O
**/
ListNode* createList()
{
    ListNode *head = NULL;
    ListNode* nodeF = insertAtBeginning(head, 'F'); // F
    ListNode* nodeE = insertAtBeginning(head, 'E'); // E->F
    ListNode* nodeD = insertAtBeginning(head, 'D'); // D->E->F
    ListNode* nodeC = insertAtBeginning(head, 'C'); // C->D->E->F
    ListNode* nodeB = insertAtBeginning(head, 'B'); // B->C->D->E->F
    ListNode* nodeA = insertAtBeginning(head, 'A'); // A->B->C->D->E->F
    head = NULL;
    ListNode* nodeJ = insertAtBeginning(head, 'J'); // J
    ListNode* nodeI = insertAtBeginning(head, 'I'); // I->J
    ListNode* nodeH = insertAtBeginning(head, 'H'); // H->I->J
    ListNode* nodeG = insertAtBeginning(head, 'G'); // G->H->I->J
    head = NULL;
    ListNode* nodeK = insertAtBeginning(head, 'K'); // K
    head = NULL;
    ListNode* nodeN = insertAtBeginning(head, 'N'); // N
    ListNode* nodeM = insertAtBeginning(head, 'M'); // M->N
    ListNode* nodeL = insertAtBeginning(head, 'L'); // L->M->N
    head = NULL;
    ListNode* nodeO = insertAtBeginning(head, 'O'); // O
    nodeC->child = nodeG;
    nodeG->child = nodeK;
    nodeJ->child = nodeL;
    nodeL->child = nodeO;
    head = nodeA;
    return head;
}

int main()
{
    ListNode* head = createList();
    head = flatten_recursive(head);
    cout << "Flattened List using recursive method:";
    printList(head);
    return 0;
}