/*
** @Author: Sandeep Thapar
**
** Flatten binary tree to linked list. The "linked list" should be in the same order
** as a pre-order traversal of the binary tree.
** It can be done using various methods - recursion, iterative using stack, iterative without extra space.
** This is the recursive method implementation
** 
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
using namespace std;

struct TreeNode
{
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

void inorder_traversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->val << " ";
    inorder_traversal(root->right);
}
    
void postorder_traversal(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val << " ";
}

TreeNode *previous = NULL;

void flatten_recursive(TreeNode* root)
{
    if (root == NULL)
        return;
    flatten_recursive(root->right);
    flatten_recursive(root->left);
    root->right = previous;
    root->left = NULL;
    previous = root;
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->left->left = new TreeNode('C');
    root->left->right = new TreeNode('D');
    root->right = new TreeNode('E');
    root->right->right = new TreeNode('F');
    root->right->right->left = new TreeNode('G');

    TreeNode *prev = NULL;
    cout << "Method 1: Flatten binary tree using recursion" << endl;
    flatten_recursive (root);
    cout << "Inorder Traversal of flattened tree: ";
    inorder_traversal (root);
    cout << endl << "Postorder Traversal of flattened tree: ";
    postorder_traversal (root);
    cout << endl << endl;

    return 0;
}



