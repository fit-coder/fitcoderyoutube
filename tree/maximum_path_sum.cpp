/*
** @Author: Sandeep Thapar
**
** Given the root of a binary tree, find the maximum path sum of any path
**
** Path -> Sequence of nodes where each pair of adjacent nodes has an edge connecting them.
** A node can only appear in the sequence at most once.
** Path does not necessarily need to pass through root
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <climits>
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

int res = INT_MIN;

int maxSum(TreeNode* root)
{
    if (root == NULL)
        return 0;
    int lsum = max (maxSum(root->left), 0);
    int rsum =  max(maxSum(root->right), 0);
    res = max (res, lsum + rsum + root->val);
    return max(lsum, rsum) + root->val;
}

int main()
{
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(7);
    root->left->left = new TreeNode(11);
    root->left->right = new TreeNode(-3);
    root->left->right->left = new TreeNode(5);
    root->left->right->right = new TreeNode(14);
    root->right = new TreeNode(6);
    root->right->left = new TreeNode(-7);
    root->right->left->right = new TreeNode(3);

    res = INT_MIN;
    maxSum(root);
    cout << "Maximum Path Sum in Binary Tree: " << res << endl;
    return 0;
}
