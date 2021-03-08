/*
** @Author: Sandeep Thapar
**
** Flatten binary tree to linked list. The "linked list" should be in the same order
** as a pre-order traversal of the binary tree.
** It can be done using various methods - recursion, iterative using stack, iterative without extra space.
** In this iterative method, no extra space is used.
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

void flatten(TreeNode *root)
{
    TreeNode* curr = root;
    while (curr != NULL)
    {
        if (curr->left != NULL)
        {
          TreeNode* prev = curr->left;
          while (prev->right)
                prev = prev->right;
          prev->right = curr->right;
          curr->right = curr->left;
          curr->left = NULL;
        }
        curr = curr->right;
    }
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

    cout << "Method 3: Flatten binary tree using without recursion and no extra space" << endl;
    flatten (root);
    cout << "Inorder Traversal of flattened tree: ";
    inorder_traversal (root);
    cout << endl << "Postorder Traversal of flattened tree: ";
    postorder_traversal (root);

    return 0;
}



