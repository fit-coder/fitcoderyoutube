/*
** @Author: Sandeep Thapar
**
** Morris (Inorder) Traversal for Binary Tree - without recursion and without stack
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

void morris_inorder_traversal(TreeNode *root)
{
    TreeNode *curr = root;
    
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            cout << curr->val << " ";
            curr = curr->right;
        }
        else
        {
            // Find the inorder predecessor of current
            TreeNode* predecessor = curr->left;
            while (predecessor->right != NULL
                   && predecessor->right != curr)
            {
                predecessor = predecessor->right;
            }

            // Make current as the right child of its inorder predecessor
            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }

            // Revert the changes, fix the right child of predecessor
            else
            {
                predecessor->right = NULL;
                cout << curr->val << " ";
                curr = curr->right;
            }
        }
    }
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->right->left = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->right = new TreeNode('C');
    root->right->right->right = new TreeNode('E');

    cout << "Morris(inorder) Traversal: ";
    morris_inorder_traversal(root);
    cout << endl;
    return 0;
}
