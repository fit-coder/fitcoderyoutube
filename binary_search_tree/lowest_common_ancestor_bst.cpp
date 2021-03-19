/*
** @Author: Sandeep Thapar
**
** Find Lowest Common Ancestor (LCA) of 2 nodes in a binary search tree
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
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data)
    {
        val = data;
        left = NULL;
        right = NULL;
    }
};

TreeNode* lca(TreeNode *node, int n1, int n2)
{
    if (node == NULL)
        return NULL;
    if (node->val > n1 && node->val > n2)
        return lca(node->left, n1, n2);
    if (node->val < n1 && node->val < n2)
        return lca(node->right, n1, n2);
    return node;
}

TreeNode* lca_iterative(TreeNode *node, int n1, int n2)
{
    while (node != NULL)
    {
        if (node->val > n1 && node->val > n2)
            node = node->left;
        else if (node->val < n1 && node->val < n2)
            node = node->right;
        else
            break;
    }
    return node;
}

int main()
{
    TreeNode *root = new TreeNode(15);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(12);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(13);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(17);
    root->right->right = new TreeNode(22);

    TreeNode *node = lca(root, 7, 13);
    cout << "LCA (Recursive method) of nodes 7 and 13 is: " << node->val << endl;
    node = lca_iterative(root, 7, 13);
    cout << "LCA (Iterative method) of nodes 7 and 13 is: " << node->val << endl;
    cout << endl;
    
    node = lca(root, 2, 10);
    cout << "LCA (Recursive method) of nodes 2 and 10 is: " << node->val << endl;
    node = lca_iterative(root, 2, 10);
    cout << "LCA (Iterative method) of nodes 2 and 10 is: " << node->val << endl;
    cout << endl;

    node = lca(root, 20, 17);
    cout << "LCA (Recursive method) of nodes 20 and 17 is: " << node->val << endl;
    node = lca_iterative(root, 20, 17);
    cout << "LCA (Iterative method) of nodes 20 and 17 is: " << node->val << endl;
    cout << endl;

    node = lca(root, 10, 17);
    cout << "LCA (Recursive method) of nodes 10 and 17 is: " << node->val << endl;
    node = lca_iterative(root, 10, 17);
    cout << "LCA (Iterative method) of nodes 10 and 17 is: " << node->val << endl;
    cout << endl;

    return 0;
}



