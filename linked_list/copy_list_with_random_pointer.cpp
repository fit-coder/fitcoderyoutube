/*
** @Author: Sandeep Thapar
**
** Given a doubly linked list with one pointer of each node pointing to the next node just
** like in a single link list. The second pointer however can point to any node in the list
** and not just the previous node. 
** Construct a copy/clone of the list and return the head of the copied linked list.
**
** I have explained two methods here to solve this problem.
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
    ListNode *random;
    ListNode(int v)
    {
        val = v;
        next = NULL;
        random = NULL;
    }
};

ListNode* insertAtBeginning(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
    return newNode;
}

// With using extra space (Hashmap)
ListNode* copyRandomList_Method1(ListNode* head)
{
    unordered_map<ListNode*, ListNode*> um;
    ListNode *prev = NULL;
    ListNode *org = head;

    // copy next pointers
    while (org != NULL)
    {
        ListNode *temp = new ListNode(org->val);
        um[org] = temp; // mapping of org->copy node
        if (prev != NULL)
            prev->next = temp;
        prev = temp;
        org = org->next;
    }

    // copy random pointers
    org = head;
    ListNode *copy = um[org];
    ListNode *res = copy;
    while (org != NULL)
    {
        if (org->random != NULL)
            copy->random = um[org->random];
        org = org->next;
        copy = copy->next;
    }
    return res;
}

// Without using extra space
ListNode* copyRandomList_Method2(ListNode* head)
{
    if (head == NULL)
        return NULL;
    ListNode* org = head;

    // insert copy of each node after it
    while (org != NULL)
    {
        ListNode* node = new ListNode(org->val);
        node->next = org->next;
        org->next = node;
        org = org->next->next;
    }
    
    // copy random pointers
    org = head;
    while (org != NULL && org->next != NULL)
    {
        if (org->random != NULL)
            org->next->random = org->random->next;
        org = org->next->next;
    }

    // separate both lists
    org = head;
    ListNode* copy = org->next;
    ListNode* res = copy;
    while (org != NULL && org->next != NULL)
    {
        org->next = org->next->next;
        if (copy->next != NULL)
            copy->next = copy->next->next;
        org = org->next;
        copy = copy->next;
    }
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
    head = h;
    cout << ", Random pointers:";
    while (head != NULL)
    {
        if (head->random == NULL)
            cout << " NULL";
        else
            cout << " " << head->random->val;
        head = head->next;
    }
    cout << endl;
}

int main()
{
    ListNode *head = NULL;
    ListNode* node1 = insertAtBeginning(head, 1); // 1
    ListNode* node10 = insertAtBeginning(head, 10); // 10->1
    ListNode* node11 = insertAtBeginning(head, 11); // 11->10->1
    ListNode* node13 = insertAtBeginning(head, 13); // 13->11->10->1
    ListNode* node7 = insertAtBeginning(head, 7); // 7->13->11->10->1
    node13->random = node7;
    node11->random = node1;
    node10->random = node11;
    node1->random = node7;

    cout << "Linked List:";
    printList(head);

    cout << "Copied Linked List using Method1:";
    ListNode *res = copyRandomList_Method1(head);
    printList(res);

    cout << "Copied Linked List using Method2:";
    res = copyRandomList_Method2(head);
    printList(res);
    return 0;
}
