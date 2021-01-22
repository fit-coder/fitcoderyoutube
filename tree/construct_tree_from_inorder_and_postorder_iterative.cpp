/*
** @Author: Sandeep Thapar
**
** Construct a binary tree from given inorder and postorder traversal - Iterative method
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <stack>
#include <vector>
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

void inorder_traversal(TreeNode *node)
{
    if (node == NULL)
        return;
    inorder_traversal(node->left);
    cout << node->val << " ";
    inorder_traversal(node->right);
}

void postorder_traversal(TreeNode *node)
{
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->val << " ";
}

TreeNode* construct_tree(vector<char>& inorder, vector<char>& postorder)
{
    int postIndex = postorder.size()-1, inIndex = inorder.size()-1, flag = 0;
    stack<TreeNode*> st;

    TreeNode* root = new TreeNode(postorder[postIndex]);
    --postIndex;
    st.push(root);
    TreeNode *prev = root;

    while (postIndex >= 0)
    {
        if (!st.empty() && inorder[inIndex] == st.top()->val)
        {
            prev = st.top();
            st.pop();
            --inIndex;
            flag = 1;
        }
        else
        {
            TreeNode* node = new TreeNode(postorder[postIndex]);
            if (flag == 0)
            {
                prev->right = node;
                prev = prev->right;
            }
            else
            {
                prev->left = node;
                prev = prev->left;
                flag = 0;
            }
            st.push(node);
            --postIndex;
        }
    }
    return root;
}

int main()
{
    vector<char> inorder = {'H','D','P','L','A','Z','C','E'};
    vector<char> postorder = {'H','P','L','D','E','C','Z','A'};

    TreeNode* root = construct_tree(inorder, postorder);

    cout << "Tree constructed" << endl;
    cout << "Inorder traversal of the constructed tree: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Postorder traversal of the constructed tree: ";
    postorder_traversal(root);
    cout << endl;
    return 0;
}

