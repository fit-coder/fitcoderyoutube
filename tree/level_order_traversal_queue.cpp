/*
** @Author: Sandeep Thapar
**
** Binary Tree Level order Traversal using Queue
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

void levelorder_traversal(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode *curr = q.front();
        cout << curr->val << " ";
        q.pop();
        if (curr->left != NULL)
            q.push(curr->left);
        if (curr->right != NULL)
            q.push(curr->right);
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

    cout << "Levelorder Traversal using Queue: ";
    levelorder_traversal(root);
    cout << endl;
    return 0;
}
