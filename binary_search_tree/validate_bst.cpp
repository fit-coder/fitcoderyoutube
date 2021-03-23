/*
** @Author: Sandeep Thapar
**
** Validate if a binary tree is a binary search tree
** Three methods are explained here
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <stack>
using namespace std;

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

bool validate_bst(TreeNode* node, TreeNode* minNode, TreeNode* maxNode)
{
    if (node == NULL)
        return true;
    if ((minNode && node->val <= minNode->val)
     || (maxNode && node->val >= maxNode->val))
        return false;
    return validate_bst(node->left, minNode, node)
        && validate_bst(node->right, node, maxNode);
}

bool validate_bst_using_inorder(TreeNode* node, TreeNode* &previous)
{
    if (node == NULL)
        return true;
    if (validate_bst_using_inorder(node->left, previous) == false)
        return false;
    if (previous != NULL && previous->val >= node->val)
        return false;
    previous = node;
    return validate_bst_using_inorder(node->right, previous);
}

bool validate_bst_using_stack(TreeNode *root)
{
    stack<TreeNode*> st;
    TreeNode* curr = root;
    TreeNode* previous = NULL;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            st.pop();
            if (previous && previous->val >= curr->val)
                return false;
            previous = curr;
            curr = curr->right;
        }
    }
    return true;
}

int main()
{
    TreeNode *root1 = new TreeNode(15);
    root1->left = new TreeNode(7);
    root1->left->left = new TreeNode(2);
    root1->left->right = new TreeNode(12);
    root1->left->right->left = new TreeNode(10);
    root1->left->right->right = new TreeNode(16);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(17);

    TreeNode *root2 = new TreeNode(15);
    root2->left = new TreeNode(7);
    root2->left->left = new TreeNode(2);
    root2->left->right = new TreeNode(12);
    root2->left->right->left = new TreeNode(10);
    root2->left->right->right = new TreeNode(13);
    root2->right = new TreeNode(20);
    root2->right->left = new TreeNode(17);

    TreeNode* previous = NULL;
    cout << "Is Tree#1 BST: " << endl;
    cout << "Method 1 result: " << validate_bst(root1, NULL, NULL) << endl;
    cout << "Method 2 result: " << validate_bst_using_inorder(root1, previous) << endl;
    cout << "Method 3 result: " << validate_bst_using_stack(root1) << endl;
    
    cout << endl;
    previous = NULL;
    cout << "Is Tree#2 BST: "<< endl;
    cout << "Method 1 result: " << validate_bst(root2, NULL, NULL) << endl;
    cout << "Method 2 result: " << validate_bst_using_inorder(root2, previous) << endl;
    cout << "Method 3 result: " << validate_bst_using_stack(root2) << endl;

    return 0;
}



