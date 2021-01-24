/*
** @Author: Sandeep Thapar
**
** Construct a binary tree from given inorder and postorder traversal - Recursive method
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

void postorder_traversal(TreeNode *node)
{
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->val << " ";
}

TreeNode* construct_tree(vector<char>& postorder,
                         unordered_map<char,int>& inorderMap,
                         int& postIndex, int inStart, int inEnd)
{
    if (inStart > inEnd)
        return NULL;

    // Pick current node from postorder traversal using postIndex
    TreeNode* node = new TreeNode(postorder[postIndex]);
    --postIndex;

    // If this node has no children then return
    if (inStart == inEnd)
        return node;

    // Else get the index of this node in Inorder traversal
    int inIndex = inorderMap[node->val];
    
    // Using index in inorder traversal, construct right and left subtrees
    node->right = construct_tree(postorder, inorderMap, postIndex, inIndex + 1, inEnd);
    node->left = construct_tree(postorder, inorderMap, postIndex, inStart, inIndex - 1);

    return node;
}

int main()
{
    vector<char> inorder = {'H','D','P','L','A','Z','C','E'};
    vector<char> postorder = {'H','P','L','D','E','C','Z','A'};

    // construct a value-to-index map for inorder traversal
    unordered_map<char,int> inorderMap;
    for (int i=0; i < inorder.size(); i++)
        inorderMap[inorder[i]] = i;

    int postIndex = postorder.size()-1;
    TreeNode* root = construct_tree(postorder, inorderMap, postIndex, 0, inorder.size()-1);
    
    cout << "Tree constructed" << endl;
    cout << "Inorder traversal of the constructed tree: ";
    inorder_traversal(root);
    cout << endl;

    cout << "Postorder traversal of the constructed tree: ";
    postorder_traversal(root);
    cout << endl;
    return 0;
}

