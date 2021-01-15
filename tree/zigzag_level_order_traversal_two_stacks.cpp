/*
** @Author: Sandeep Thapar
**
** Binary Tree ZigZag Level order Traversal using 2 Stacks
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <stack>
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

// Zigzag level order traversal using 2 stacks
void zigzag_levelorder_traversal_twostacks(TreeNode *root)
{
    stack<TreeNode*> st1, st2;
    st1.push(root);
    TreeNode *curr = NULL;

    while (!st1.empty() || st2.empty())
    {
        while (!st1.empty())
        {
            curr = st1.top();
            st1.pop();
            cout << curr->val << " ";
            if (curr->right != NULL)
                st2.push(curr->right);
            if (curr->left != NULL)
                st2.push(curr->left);
        }
        while (!st2.empty())
        {
            curr = st2.top();
            st2.pop();
            cout << curr->val << " ";
            if (curr->left != NULL)
                st1.push(curr->left);
            if (curr->right != NULL)
                st1.push(curr->right);
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

    cout << "ZigZag Levelorder Traversal using two stacks: ";
    zigzag_levelorder_traversal_twostacks(root);
    cout << endl;

    return 0;
}
