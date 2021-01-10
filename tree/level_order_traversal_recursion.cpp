/*
** @Author: Sandeep Thapar
**
** Binary Tree Level order Traversal using recursion
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

int height(TreeNode *node)
{
    if (node == NULL)
       return -1;
    int lheight = height(node->left);
    int rheight = height(node->right);
    return max(lheight, rheight) + 1;
}

void print_level(TreeNode *node, int level)
{
    if (node == NULL)
       return;
    else if (level == 0)
       cout << node->val << " ";
    else if (level > 0)
    {
        print_level(node->left, level-1);
        print_level(node->right, level-1);
    }
}

void levelorder_traversal(TreeNode *root)
{
    cout << height(root) << endl;
    for (int level=0; level <= height(root); level++)
        print_level(root, level);
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

    cout << "Levelorder Traversal using recursion: ";
    levelorder_traversal(root);
    cout << endl;
    return 0;
}
