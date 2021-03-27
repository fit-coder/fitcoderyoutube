/*
** @Author: Sandeep Thapar
**
** Create a Balanced Binary Search Tree from a sorted array
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <vector>
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

void inorder_traversal(TreeNode* root)
{
    if (root == NULL)
        return;
    inorder_traversal(root->left);
    cout << root->val << " ";
    inorder_traversal(root->right);
}

void preorder_traversal(TreeNode* root)
{
    if (root == NULL)
        return;
    cout << root->val << " ";
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

TreeNode* sorted_array_to_bst(vector<int>&v, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = start + (end - start) / 2;
    TreeNode* node = new TreeNode(v[mid]);
    node->left = sorted_array_to_bst (v, start, mid-1);
    node->right = sorted_array_to_bst (v, mid+1, end);
    return node;
}

int main()
{
    vector<int> v = {11,22,33,44,55,66,77,88};
    
    TreeNode* root = sorted_array_to_bst(v, 0, v.size()-1);
    cout << "Balanced BST created from {11,22,33,44,55,66,77,88}" << endl;
    
    cout << "Inorder Traversal:  ";
    inorder_traversal(root);
    cout << endl;

    cout << "Preorder Traversal: ";
    preorder_traversal(root);
    cout << endl;

    return 0;
}
