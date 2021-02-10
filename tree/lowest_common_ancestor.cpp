/*
** @Author: Sandeep Thapar
**
** Find lowest common ancestor of 2 nodes n1 and n2 in a binary Tree
** Assumptions: n1 and n2 exist in tree and tree contains unique values
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
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

TreeNode* lca(TreeNode *node, char n1, char n2)
{
    if (node == NULL)
       return NULL;
    if (node->val == n1 || node->val == n2)
       return node;

    TreeNode *left = lca(node->left, n1, n2);
    TreeNode *right = lca(node->right, n1, n2);
    if (left != NULL && right != NULL)
        return node;
    else if (left != NULL)
        return left;
    else
        return right;
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
    root->right->left->right = new TreeNode('G');

    cout << "Lowest Common Ancestor of D and P: ";
    TreeNode* node = lca(root, 'D', 'P');
    cout << node->val << endl;
    
    cout << "Lowest Common Ancestor of H and P: ";
    node = lca(root, 'H', 'P');
    cout << node->val << endl;

    cout << "Lowest Common Ancestor of Z and B: ";
    node = lca(root, 'Z', 'B');
    cout << node->val << endl;

    cout << "Lowest Common Ancestor of L and B: ";
    node = lca(root, 'L', 'B');
    cout << node->val << endl;

    return 0;
}
