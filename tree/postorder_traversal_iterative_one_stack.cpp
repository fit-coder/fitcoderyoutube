/*
** @Author: Sandeep Thapar
**
** Binary Tree Postorder Traversal - iterative version using one stack
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

void postorder_traversal(TreeNode *root)
{
    stack<TreeNode*> st;
    TreeNode *curr = root;
    TreeNode *prev = NULL;
    while (curr != NULL || !st.empty())
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            curr = st.top();
            if (curr->right == NULL || curr->right == prev)
            {
                cout << curr->val << " ";
                st.pop();
                prev = curr;
                curr = NULL;
            }
            else
                curr = curr->right;
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

    cout << "Postorder Traversal using one stack: ";
    postorder_traversal(root);
    cout << endl;
    return 0;
}
