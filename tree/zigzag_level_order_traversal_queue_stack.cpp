/*
** @Author: Sandeep Thapar
**
** Binary Tree ZigZag Level order Traversal using a Queue and Stack
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <stack>
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

// Zigzag level order traversal using 1 queue and 1 stack
void zigzag_levelorder_traversal_queuestack(TreeNode *root)
{
    queue<TreeNode*> q;
    q.push(root);

    stack<TreeNode*> st;
    bool ltr = false;
    TreeNode *curr = NULL;

    while (!q.empty())
    {
        int size = q.size();
        while (size)
        {
            --size;
            curr = q.front();
            q.pop();
            if (ltr)
                cout << curr->val << " ";
            else
                st.push(curr);
            if (curr->left != NULL)
                q.push(curr->left);
            if (curr->right != NULL)
                q.push(curr->right);
        }
        if (ltr == false)
        {
            while (!st.empty())
            {
                curr = st.top();
                st.pop();
                cout << curr->val << " ";
            }
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

    cout << "ZigZag Levelorder Traversal using queue and stack: ";
    zigzag_levelorder_traversal_queuestack(root);
    cout << endl;

    return 0;
}
