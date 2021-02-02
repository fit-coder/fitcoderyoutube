/*
** @Author: Sandeep Thapar
**
** Find height of binary Tree - Both recursive and iterative method
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

int height_iterative(TreeNode *root)
{
    int height = -1;
    if (root == NULL)
       return height;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        ++height;
        int size = q.size();
        while (size > 0)
        {
            --size;
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left != NULL)
               q.push(curr->left);
            if (curr->right != NULL)
               q.push(curr->right);
        }
    }
    return height;
}

int height_recursive(TreeNode *node)
{
    if (node == NULL)
       return -1;
    int lheight = height_recursive(node->left);
    int rheight = height_recursive(node->right);
    return max(lheight, rheight) + 1;
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->left->left = new TreeNode('K');
    root->left->right = new TreeNode('L');
    root->left->right->right = new TreeNode('P');
    root->left->right->right->right = new TreeNode('E');
    root->right = new TreeNode('Z');
    root->right->left = new TreeNode('B');
    root->right->right = new TreeNode('C');

    cout << "Height of the tree (recursive method): ";
    cout << height_recursive(root) << endl;
    cout << endl;

    cout << "Height of the tree (iterative method): ";
    cout << height_iterative(root) << endl;
    cout << endl;
    return 0;
}
