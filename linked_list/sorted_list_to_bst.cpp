/*
** @Author: Sandeep Thapar
**
** Given the head of a sorted linked list, create a balanced BST from it
** Height-balanced BST is defined as a BST in which the depth of the two subtrees of every node
** never differ by more than 1.
**
** e.g Input: 11->22->33->44->55->66->77->88
** Output:    44
**          /    \
**         /      \
**        22      66 
**       /  \     /  \
**      11  33   55  77
**                     \
**                     88
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
        val = -1;
        next = NULL;
    }
    ListNode(int v)
    {
        val = v;
        next = NULL;
    }
};

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inorderTraversal(TreeNode* root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

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

int findLength(ListNode *head)
{
    int length = 0;
    while (head != NULL) 
    {
        head = head->next;
        ++length;
    }
    return length;
}

TreeNode* construct(ListNode* &head, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start)/2;
    TreeNode *left = construct(head, start, mid-1);
    TreeNode *node = new TreeNode(head->val);
    node->left = left;
    head = head->next;
    node->right = construct(head, mid+1, end);
    return node;
}

TreeNode* sortedListToBST(ListNode* head)
{
    int length = findLength (head);
    return construct(head, 0, length-1);
}

ListNode* createLinkedList()
{
    ListNode *head = NULL;
    insertAtBeginning(head, 88); // 88
    insertAtBeginning(head, 77); // 77->88
    insertAtBeginning(head, 66); // 66->77->88
    insertAtBeginning(head, 55); // 55->66->77->88
    insertAtBeginning(head, 44); // 44->55->66->77->88
    insertAtBeginning(head, 33); // 33->44->55->66->77->88
    insertAtBeginning(head, 22); // 22->33->44->55->66->77->88
    insertAtBeginning(head, 11); // 11->22->33->44->55->66->77->88
    return head;
}

int main()
{
    ListNode* head = createLinkedList();
    cout << "Linked List:";
    printList(head); // 11->22->33->44->55->66->77->88

    TreeNode* root = sortedListToBST(head);
    cout << "Balanced BST created from Linked List" << endl;
    
    cout << "Inorder Traversal:  ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}
