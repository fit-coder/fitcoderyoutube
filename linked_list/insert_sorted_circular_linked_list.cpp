/*
** @Author: Sandeep Thapar
**
** Given a random node of a circular linked list sorted in ascending order,
** insert a value key into the list such that it remains a sorted circular list.
**
** Input: 1->3->4->8, key=6. Pointer is given to node 3
** Output: 1->3->4->6->8
**
** Input: 2->5->6->9->20->35, key=4. Pointer is given to node 9
** Output: 2->4->5->6->9->20->35
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
    int val;
    ListNode *next;
    ListNode(int v)
    {
        val = v;
        next = NULL;
    }
};

ListNode* insertAtBeginning(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
    return newNode;
}

// Here head is pointer to random node of circular sorted linked list
ListNode* circularSortedInsert(ListNode *head, int key)
{
    ListNode *newNode = new ListNode(key);
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    ListNode* prev = head;
    ListNode* curr = head->next;
    while (curr != head)
    {
        if ((key >= prev->val && key <= curr->val)
         || (key < curr->val && prev->val > curr->val)
         || (key > prev->val && prev->val > curr->val))
        {
            break;
        }
        prev = prev->next;
        curr = curr->next;
    }
    prev->next = newNode;
    newNode->next = curr;
    return head;
}

void printList(ListNode *head, int count)
{
    while (count != 0)
    {
        cout << " " << head->val;
        --count;
        head = head->next;
    }
}

pair<ListNode*, int> createList()
{
    ListNode* head = NULL;
    head = insertAtBeginning(head, 35); // 35
    ListNode* nodeLast = head; // pointer to node 35
    head = insertAtBeginning(head, 20); // 20->35
    head = insertAtBeginning(head, 9); // 9->20->35
    ListNode* node = head;
    head = insertAtBeginning(head, 6); // 6->9->20->35
    head = insertAtBeginning(head, 5); // 5->6->9->20->35
    head = insertAtBeginning(head, 2); // 2->5->6->9->20->35
    nodeLast->next = head;

    int count = 6;
    cout << "Linked List:";
    printList(node, count);
    cout << endl;

    return {node, count};
}

int main()
{
    auto [head, count] = createList();

    int key = 4;
    head = circularSortedInsert(head, key);
    cout << "Linked List after inserting key=4: ";
    printList(head, count+1);
    return 0;
}