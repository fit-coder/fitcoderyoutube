/*
** @Author: Sandeep Thapar
**
** Given the head of a linked list and a value x, partition it such that all nodes less than x
** come before nodes greater than or equal to x.
** You should preserve the original relative order of the nodes in each of the two partitions.
**
** e.g Input: 1->4->3->2->5->2, x = 3
** Output: 1->2->2->4->3->5
**
** e.g Input: 5->6->9->1->4->3, x = 4
** Output: 1->3->5->6->9->4
**
** For video explanation, please refer to my Youtube channel (youtube.com/fitcoder) in the link below:
** https://youtube.com/playlist?list=PLFj4kIJmwGu1oI1HVzAZlpJgKf9xv6mM1
**
** Please subscribe to the channel if you find this helpful
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = NULL;
    }
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

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

ListNode* partition(ListNode* head, int x)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *dummy1 = new ListNode();
    ListNode *dummy2 = new ListNode();
    ListNode *head1 = dummy1;
    ListNode *head2 = dummy2;  
    while (head != NULL)
    {
        if (head->val < x)
        {
            head1->next = head;
            head1 = head1->next;
        }
        else
        {
            head2->next = head;
            head2 = head2->next;
        }
        head = head->next;
    }
    head1->next = dummy2->next;
    head2->next = NULL;
    ListNode *res = dummy1->next;
    delete dummy1;
    delete dummy2;
    return res;
}

vector<ListNode*> createLinkedLists()
{
    ListNode *head1 = NULL;
    insertAtBeginning(head1, 3); // 3
    insertAtBeginning(head1, 4); // 4->3
    insertAtBeginning(head1, 1); // 1->4->3
    insertAtBeginning(head1, 9); // 9->1->4->3
    insertAtBeginning(head1, 6); // 6->9->1->4->3
    insertAtBeginning(head1, 5); // 5->6->9->1->4->3

    ListNode *head2 = NULL;
    insertAtBeginning(head2, 2); // 2
    insertAtBeginning(head2, 5); // 5->2
    insertAtBeginning(head2, 2); // 2->5->2
    insertAtBeginning(head2, 3); // 3->2->5->2
    insertAtBeginning(head2, 4); // 4->3->2->5->2
    insertAtBeginning(head2, 1); // 1->4->3->2->5->2
    return {head1, head2};
}

int main()
{
    auto v = createLinkedLists();
    ListNode* head1 = v[0], *head2 = v[1];

    cout << "Linked List 1:";
    printList(head1); // 5->6->9->1->4->3
    ListNode *newHead = partition(head1, 4);
    cout << "Linked List 1 after partitioning around 4:";
    printList(newHead);
    cout << endl;

    cout << "Linked List 2:";
    printList(head2); // 1->4->3->2->5->2
    newHead = partition(head2, 3);
    cout << "Linked List 2 after partitioning around 3:";
    printList(newHead);

    return 0;
}
