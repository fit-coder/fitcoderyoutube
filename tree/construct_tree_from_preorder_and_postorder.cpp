/*
** @Author: Sandeep Thapar
**
** Construct a full binary tree from given preorder and postorder traversal
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

void preorder_traversal(TreeNode *node)
{
    if (node == NULL)
        return;
    cout << node->val << " ";
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void postorder_traversal(TreeNode *node)
{
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);
    cout << node->val << " ";
}

TreeNode* construct_tree(vector<char>& preorder,
                         unordered_map<char,int>& postorderMap,
                         int& preIndex, int postStart, int postEnd)
{
    if (postStart > postEnd)
        return NULL;
    TreeNode *node = new TreeNode(preorder[preIndex]);
    ++preIndex;
    if (postStart == postEnd)
        return node;
    int postIndex = postorderMap[preorder[preIndex]];
    node->left = construct_tree(preorder, postorderMap, preIndex, postStart, postIndex);
    node->right = construct_tree(preorder, postorderMap, preIndex, postIndex+1, postEnd-1);
    return node;
}

int main()
{
    vector<char> preorder = {'A','D','H','L','Z','P','C'};
    vector<char> postorder = {'H','L','D','P','C','Z','A'};

    unordered_map<char,int> postorderMap;
    for (int i=0; i < postorder.size(); i++)
        postorderMap[postorder[i]] = i;;
    
    int preIndex = 0;
    TreeNode* root = construct_tree(preorder, postorderMap, preIndex, 0, postorder.size()-1);

    cout << "Full binary Tree constructed" << endl;
    cout << "Preorder traversal of the constructed tree: ";
    preorder_traversal(root);
    cout << endl;

    cout << "Postorder traversal of the constructed tree: ";
    postorder_traversal(root);
    cout << endl;
    return 0;
}

