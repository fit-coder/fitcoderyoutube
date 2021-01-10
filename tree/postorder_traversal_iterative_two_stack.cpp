/*
** @Author: Sandeep Thapar
**
** Binary Tree Postorder Traversal - iterative version using two stacks
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
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode *curr = NULL;

    st1.push(root);
    while (!st1.empty())
    {
        curr = st1.top();
        st1.pop();
        st2.push(curr);
        if (curr->left != NULL)
            st1.push(curr->left);
        if (curr->right != NULL)
            st1.push(curr->right);
    }
    while (!st2.empty())
    {
        curr = st2.top();
        cout << curr->val << " ";
        st2.pop();
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

    cout << "Postorder Traversal using two stacks: ";
    postorder_traversal(root);
    cout << endl;
    return 0;
}
