/*
** @Author: Sandeep Thapar
**
** XOR linked list is a memory efficient version of Doubly Linked List that can be created using only
** one space for address field with every node.
** In the XOR linked list, instead of storing actual memory addresses, every node stores the
** XOR of addresses of previous and next nodes.
**
** For video explanation, please refer to my Youtube channel in the link below:
** Channel: youtube.com/fitcoder
** BST Playlist: https://youtube.com/playlist?list=PLFj4kIJmwGu21Tv1mmsNFOf5pWUrSjr55
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

struct XorListNode
{
    char val;
    XorListNode *npx;
    XorListNode()
    {
        val = ' ';
        npx = NULL;
    }
    XorListNode(char v)
    {
        val = v;
        npx = NULL;
    }
};

XorListNode* XOR(XorListNode *x, XorListNode *y)
{
    return (XorListNode*)((uintptr_t)(x) ^ (uintptr_t)(y));
}

void traverseForward(XorListNode *node)
{
    XorListNode* prev = NULL;
    XorListNode* curr = node;
    while (curr != NULL)
    {
        cout << " " << curr->val;
        XorListNode *temp = XOR(curr->npx, prev);
        prev = curr;
        curr = temp;
    }
}

void traverseBackward(XorListNode *node)
{
    XorListNode* next = NULL;
    XorListNode* curr = node;
    while (curr != NULL)
    {
        cout << " " << curr->val;
        XorListNode *temp = XOR(curr->npx, next);
        next = curr;
        curr = temp;
    }
}

void insertAtBeginning(XorListNode *&head, char data)
{
    XorListNode *newNode = new XorListNode(data);
    newNode->npx = head;
    if (head != NULL)
    {
        head->npx = XOR (head->npx, newNode);
    }
    head = newNode;
}

int main ()
{
    XorListNode *head = NULL;
    insertAtBeginning(head, 'E'); // E
    XorListNode* end = head; // points to 'E'
    insertAtBeginning(head, 'D'); // D->E
    insertAtBeginning(head, 'C'); // C->D->E
    insertAtBeginning(head, 'B'); // B->C->D->E
    insertAtBeginning(head, 'A'); // A->B->C->D->E

    cout << "Linked List Traversal in Forward Direction:";
    traverseForward(head);
    cout << endl;

    cout << "Linked List Traversal in Backward Direction:";
    traverseBackward(end);
    return 0;
}
