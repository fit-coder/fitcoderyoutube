/*
** @Author: Sandeep Thapar
**
** Given the head of a singly linked list, return true if it is a palindrome
**
** e.g Input: A->B->C->C->B->A
** Output: True
**
** e.g Input: A->B->C->B->A
** Output: True
**
** e.g Input: A->B->C->C->B
** Output: False
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

void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << " " << head->val;
        head = head->next;
    }
    cout << endl;
}

ListNode* findMiddle(ListNode* head)
{
    if (head == NULL)
        return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

ListNode* reverse(ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

bool isPalindrome(ListNode* head) // A->B->C->D->B->A
{
    ListNode *mid = findMiddle(head); // D->B->A
    mid = reverse(mid); // A->B->D
    while (mid != NULL)
    {
        if (head->val != mid->val)
            return false;
        head = head->next;
        mid = mid->next;
    }
    return true;
}

vector<ListNode*> createLinkedLists()
{
    ListNode *head1 = NULL;
    insertAtBeginning(head1, 'A'); // A
    insertAtBeginning(head1, 'B'); // B->A
    insertAtBeginning(head1, 'C'); // C->B->A
    insertAtBeginning(head1, 'C'); // C->C->B->A
    insertAtBeginning(head1, 'B'); // B->C->C->B->A
    insertAtBeginning(head1, 'A'); // A->B->C->C->B->A

    ListNode *head2 = NULL;
    insertAtBeginning(head2, 'A'); // A
    insertAtBeginning(head2, 'B'); // B->A
    insertAtBeginning(head2, 'C'); // C->B->A
    insertAtBeginning(head2, 'B'); // B->C->B->A
    insertAtBeginning(head2, 'A'); // A->B->C->B->A

    ListNode *head3 = NULL;
    insertAtBeginning(head3, 'A'); // A
    insertAtBeginning(head3, 'B'); // B->A
    insertAtBeginning(head3, 'D'); // D->B->A
    insertAtBeginning(head3, 'C'); // C->D->B->A
    insertAtBeginning(head3, 'B'); // B->C->D->B->A
    insertAtBeginning(head3, 'A'); // A->B->C->D->B->A
    return {head1, head2, head3};
}

int main()
{
    auto v = createLinkedLists();
    ListNode *head1 = v[0];
    ListNode *head2 = v[1];
    ListNode *head3 = v[2];

    cout << "Linked List 1:";
    printList(head1); // A->B->C->C->B->A
    cout << "Is Linked List1 Palindrome: " << isPalindrome(head1);
    cout << endl;

    cout << "Linked List 2:";
    printList(head2); // A->B->C->B->A
    cout << "Is Linked List2 Palindrome: " << isPalindrome(head2);
    cout << endl;

    cout << "Linked List 3:";
    printList(head3); // A->B->C->D->B->A
    cout << "Is Linked List3 Palindrome: " << isPalindrome(head3);

    return 0;
}
