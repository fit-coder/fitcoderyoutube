/*
** @Author: Sandeep Thapar
**
** Find diameter of a binary Tree
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <queue>
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

int height(TreeNode *node, int& d)
{
    if (node == NULL)
       return -1;
    int lheight = height(node->left, d);
    int rheight = height(node->right, d);
    d = max (d, lheight + rheight + 2);
    return max(lheight, rheight) + 1;
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->right->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->right = new TreeNode('C');
    root->right->right->right = new TreeNode('G');
    root->right->right->left = new TreeNode('B');
    root->right->right->left->right = new TreeNode('E');

    cout << "Diameter of the tree: ";
    int d = 0;
    height(root, d);
    cout << d << endl;

    return 0;
}
