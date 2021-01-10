/*
** @Author: Sandeep Thapar
**
** Linked representation of a binary tree
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

int main()
{
    TreeNode* root = new TreeNode('M');
    root->left = new TreeNode('P');
    root->right = new TreeNode('Q');
    root->left->left = new TreeNode('A');
    root->left->right = new TreeNode('D');
    root->right->left = new TreeNode('B');
    root->right->right = new TreeNode('C');
    root->right->right->right = new TreeNode('W');
    return 0;
}
