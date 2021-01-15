/*
** @Author: Sandeep Thapar
**
** Binary Tree ZigZag Level order Traversal using Deque
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

void zigzag_levelorder_traversal_deque(TreeNode *root)
{
    if (root == NULL)
        return;
    deque<TreeNode*> dq;
    dq.push_back(root);
    bool ltr = false;

    while (!dq.empty())
    {
        int size = dq.size();
        while (size > 0)
        {
            if (ltr)
            {
                TreeNode* curr = dq.front();
                dq.pop_front();
                cout << curr->val << " ";
                if (curr->left)
                    dq.push_back(curr->left);
                if (curr->right)
                    dq.push_back(curr->right);
            }
            else
            {
                TreeNode* curr = dq.back();
                dq.pop_back();
                cout << curr->val << " ";
                if (curr->right)
                    dq.push_front(curr->right);
                if (curr->left)
                    dq.push_front(curr->left);
            }
            --size;
        }
        ltr = !ltr;
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

    cout << "ZigZag Levelorder Traversal using deque: ";
    zigzag_levelorder_traversal_deque(root);
    cout << endl;
    return 0;
}
