/*
** @Author: Sandeep Thapar
**
** Given the heads of K sorted linked lists, merge the K lists into 1 sorted linked list
** and return its head.
**
** e.g Input: head1 = 1->2->7->10
**            head2 = 8->9->12
**            head2 = 2->6
**            head2 = 3->5->6->8->20
** Output: 1->2->2->3->5->6->6->7->8->8->9->10->12->20
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
    ListNode(int v)
    {
        val = v;
        next = NULL;
    }
};

void insertAtBeginning(ListNode *&head, int data)
{
    ListNode *newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

struct comp
{
    bool operator()(ListNode*& l1, ListNode*& l2)
    {
        return l1->val > l2->val;
    }
};

ListNode* mergeKLists(vector<ListNode*> lists)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* prevNode = dummy;

    priority_queue<ListNode*, vector<ListNode*>, comp> pq; // min heap
    for (int i=0; i < lists.size(); ++i)
    {
        if (lists[i] != NULL)
            pq.push(lists[i]);
    }
    while (!pq.empty())
    {
        auto node = pq.top();
        pq.pop();
        if (node->next != NULL)
            pq.push(node->next);
        prevNode->next = node;
        prevNode = node;
    }
    ListNode* res = dummy->next;
    delete dummy;
    return res;
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

int main()
{
    int k = 4;
    vector<ListNode*> lists(k);
    insertAtBeginning(lists[0], 10); // 10
    insertAtBeginning(lists[0], 7); // 7->10
    insertAtBeginning(lists[0], 2); // 2->7->10
    insertAtBeginning(lists[0], 1); // 1->2->7->10

    insertAtBeginning(lists[1], 12); // 12
    insertAtBeginning(lists[1], 9); // 9->12
    insertAtBeginning(lists[1], 8); // 8->9->12

    insertAtBeginning(lists[2], 6); // 6
    insertAtBeginning(lists[2], 2); // 2->6

    insertAtBeginning(lists[3], 20); // 20
    insertAtBeginning(lists[3], 8); // 8->20
    insertAtBeginning(lists[3], 6); // 6->8->20
    insertAtBeginning(lists[3], 5); // 5->6->8->20
    insertAtBeginning(lists[3], 3); // 3->5->6->8->20

    for (int i=0; i < k; ++i)
    {
        cout << "Sorted Linked List " << i+1 << ":";
        printList(lists[i]);
    }

    cout << "Merged Sorted List :";
    ListNode *res = mergeKLists(lists);
    printList(res);
    return 0;
}
