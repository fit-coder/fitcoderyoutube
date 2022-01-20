/*
** @Author: Sandeep Thapar
**
** You are given a doubly linked list, which contains nodes that have a next pointer,
** a previous pointer, and an additional child pointer. This child pointer may or may not
** point to a separate doubly linked list, also containing these special nodes.
** Given the head of the first level of the list, flatten the list so that all the nodes
** appear in a single-level, doubly linked list
**
** Here I have explained iterative method to solve this problem.
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

ListNode* flatten_iterative(ListNode* head)
{
    if (head == NULL)
        return NULL;
    stack<ListNode*> st;
    st.push(head);
    ListNode* currNode = NULL, *prevNode = NULL;
    while (!st.empty())
    {
        currNode = st.top();
        st.pop();
        if (currNode->next != NULL)
            st.push(currNode->next);
        if (currNode->child != NULL)
            st.push(currNode->child);
        currNode->child = NULL;
        currNode->prev = prevNode;
        if (prevNode != NULL)
            prevNode->next = currNode;
        prevNode = currNode;
    }
    return head;
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
    cout << "Flattened List using iterative method:";
    head = flatten_iterative(head);
    printList(head);

    return 0;
}