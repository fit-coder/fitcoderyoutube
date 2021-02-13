/*
** @Author: Sandeep Thapar
**
** Find left view, right view of a binary Tree using iterative method
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

void left_view(TreeNode *node)
{
    if (node == NULL)
        return;
    queue<TreeNode*> q;
    q.push(node);

    while (!q.empty())
    {
        int size = q.size();
        for (int i=1; i <= size; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if (i == 1)
                cout << curr->val << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

void right_view(TreeNode *node)
{
    if (node == NULL)
        return;
    queue<TreeNode*> q;
    q.push(node);

    while (!q.empty())
    {
        int size = q.size();
        for (int i=1; i <= size; i++)
        {
            TreeNode* curr = q.front();
            q.pop();
            if (i == size)
                cout << curr->val << " ";
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
    }
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('D');
    root->left->left = new TreeNode('H');
    root->left->right = new TreeNode('L');
    root->left->right->right = new TreeNode('P');
    root->right = new TreeNode('Z');
    root->right->left = new TreeNode('C');
    root->right->left->left = new TreeNode('B');
    root->right->left->left->right = new TreeNode('G');

    cout << "Left View of the tree (Iterative method): ";
    left_view(root);
    cout << endl;

    cout << "Right View of the tree (Iterative method): ";
    right_view(root);
    cout << endl;

    return 0;
}

