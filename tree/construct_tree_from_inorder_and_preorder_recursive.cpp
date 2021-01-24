/*
** @Author: Sandeep Thapar
**
** Construct a binary tree from given inorder and preorder traversal - Recursive method
**
** For video explanation, please refer to my Youtube channel in the link below:
** https://www.youtube.com/channel/UCX6rLou1VXXPVsORMVkUryg/videos
**
** Please subscribe to the channel if you find this helpful
*/

#include <iostream>
#include <unordered_map>
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

void preorder_traversal(TreeNode *node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

TreeNode* construct_tree(vector<char>& preorder,
                         unordered_map<char,int>& inorderMap,
                         int& preIndex, int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    // Pick current node from preorder traversal using preIndex
    TreeNode* node = new TreeNode(preorder[preIndex]);
    ++preIndex;

    if (inStart == inEnd)
        return node;

    // Else get the index of this node in Inorder traversal
    int inIndex = inorderMap[node->val];
    
    // Using index in inorder traversal, construct left and right subtrees
    node->left = construct_tree(preorder, inorderMap, preIndex, inStart, inIndex - 1);
    node->right = construct_tree(preorder, inorderMap, preIndex, inIndex + 1, inEnd);

    return node;
}

int main()
{
    vector<char> inorder = {'H','D','P','L','A','Z','C','E'};
    vector<char> preorder = {'A','D','H','L','P','Z','C','E'};

    // construct a value-to-index map for inorder traversal
    unordered_map<char,int> inorderMap;
    for (int i=0; i < inorder.size(); i++)
        inorderMap[inorder[i]] = i;

    int preIndex = 0;
    TreeNode* root = construct_tree(preorder, inorderMap, preIndex, 0, inorder.size()-1);
    
    cout << "Tree constructed" << endl;
    cout << "Inorder traversal of the constructed tree: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Preorder traversal of the constructed tree: ";
    preorder_traversal(root);
    cout << endl;
    return 0;
}

