/*
** @Author: Sandeep Thapar
**
** Find boundary traversal of a binary Tree
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

void print_left_boundary(TreeNode* node)
{
    if (node == NULL)
        return;
    if (node->left)
    {
        cout << node->val << " ";
        print_left_boundary(node->left);
    }
    else if (node->right)
    {
        cout << node->val << " ";
        print_left_boundary(node->right);
    }
}

void print_right_boundary(TreeNode* node)
{
    if (node == NULL)
        return;
    if (node->right)
    {
        print_right_boundary(node->right);
        cout << node->val << " ";
    }
    else if (node->left)
    {
        print_right_boundary(node->left);
        cout << node->val << " ";
    }
}

void print_leaves(TreeNode* node)
{
    if (node == NULL)
        return;

    print_leaves(node->left);
    if (node->left == NULL && node->right == NULL)
        cout << node->val << " ";
    print_leaves(node->right);
}

void boundary_traversal(TreeNode *root)
{
    if (root == NULL)
       return;
    cout << root->val << " ";
    print_left_boundary (root->left);
    print_leaves (root->left);
    print_leaves (root->right);
    print_right_boundary (root->right);
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->left->right = new TreeNode('K');
    root->left->left->right->left = new TreeNode('N');
    root->left->right = new TreeNode('L');
    root->left->right->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->left = new TreeNode('M');
    root->right->right = new TreeNode('C');
    root->right->right->left = new TreeNode('B');
    root->right->right->left->left = new TreeNode('R');

    cout << "Boundary Traversal of the tree: ";
    boundary_traversal(root);

    return 0;
}


