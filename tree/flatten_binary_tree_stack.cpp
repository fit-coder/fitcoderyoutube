/*
** @Author: Sandeep Thapar
**
** Flatten binary tree to linked list. The "linked list" should be in the same order
** as a pre-order traversal of the binary tree.
** It can be done using various methods - recursion, iterative using stack, iterative without extra space.
** In this iterative method, stack is used
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

void inorder_traversal(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->val << " ";
    inorder_traversal(root->right);
}
    
void postorder_traversal(TreeNode *root)
{
    if (root == NULL)
        return;
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->val << " ";
}

void flatten(TreeNode* root)
{
    if (root == NULL)
        return;
    stack<TreeNode*> st;
    st.push(root);
    while (!st.empty())
    {
        TreeNode* curr = st.top();
        st.pop();
        if (curr->right != NULL)
            st.push(curr->right);
        if (curr->left != NULL)
            st.push(curr->left);
        if (!st.empty())
            curr->right = st.top();
        curr->left = NULL;
    }
}

int main()
{
    TreeNode* root = new TreeNode('A');
    root->left = new TreeNode('B');
    root->left->left = new TreeNode('C');
    root->left->right = new TreeNode('D');
    root->right = new TreeNode('E');
    root->right->right = new TreeNode('F');
    root->right->right->left = new TreeNode('G');

    cout << "Method 2: Flatten binary tree using stack" << endl;
    flatten (root);
    cout << "Inorder Traversal of flattened tree: ";
    inorder_traversal (root);
    cout << endl << "Postorder Traversal of flattened tree: ";
    postorder_traversal (root);

    return 0;
}



