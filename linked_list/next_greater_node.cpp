/*
** @Author: Sandeep Thapar
**
** For each node in the list, find the value of the next greater node.
** That is, for each node, find the value of the first node that is next to it
** and has a strictly larger value than it.
** Return an integer array result where result[i] is the value of the next greater
** node of the ith node. If the ith node does not have a next greater node, set result[i] = 0.
**
** e.g Input: 2->1->5
** Output: [5,5,0]
**
** e.g Input: 2->7->4->3->5
** Output: [7,0,5,5,0]
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
    ListNode()
    {
        val = ' ';
        next = NULL;
    }
    ListNode(int v)
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
        cout << head->val;
        head = head->next;
        if (head != NULL)
            cout << "->";
    }
    cout << endl;
}

void printArray(vector<int>& v)
{
    int size = v.size();
    for (int i=0; i < size; ++i)
    {
        cout << v[i];
        if (i != size-1)
            cout << ",";
    }
    cout << endl << endl;
}

ListNode *reverseLL(ListNode * head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
        ListNode *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

vector<int> nextLargerNodes(ListNode* head)
{
    vector<int> res;
    stack<int> st;
    head = reverseLL(head);
    while (head != NULL)
    {
        if (st.empty())
        {
            res.push_back(0);
            st.push(head->val);
            head = head->next;
        }
        else if (st.top() > head->val)
        {
            res.push_back(st.top());
            st.push(head->val);
            head = head->next;
        }
        else
            st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

vector<ListNode*> createLinkedLists()
{
    ListNode *head1 = NULL, *head2 = NULL;
    insertAtBeginning(head1, 5); // 5
    insertAtBeginning(head1, 1); // 1->5
    insertAtBeginning(head1, 2); // 2->1->5
    
    insertAtBeginning(head2, 5); // 5
    insertAtBeginning(head2, 3); // 3->5
    insertAtBeginning(head2, 4); // 4->3->5
    insertAtBeginning(head2, 7); // 7->4->3->5
    insertAtBeginning(head2, 2); // 2->7->4->3->5
    return {head1, head2};
}

int main()
{
    auto v = createLinkedLists();
    ListNode *head1 = v[0], *head2 = v[1];

    cout << "Linked List1: ";
    printList(head1); // 2->1->5
    vector<int> result = nextLargerNodes(head1);
    cout << "Next Larger Nodes: ";
    printArray(result);

    cout << "Linked List2: ";
    printList(head2); // 2->7->4->3->5
    result = nextLargerNodes(head2);
    cout << "Next Larger Nodes: ";
    printArray(result);

    return 0;
}
